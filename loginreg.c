#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define productsize_limit 2000 //maximum products that can be in file is defined as 2000
typedef struct{
    char product_name[100];
    int product_code;
    char product_description[500];
    float product_price;
    int product_quantity;
    char last_update[100];
}product_list;

//counts products from the file and loads the products into an array
int counting_product_from_file(char *product_file, product_list* products){
    FILE *fptr;
    fptr = fopen(product_file,"r");
    if (fptr==NULL){
        printf("Error in loading the products\n");
        exit(1);
    }
    int count = 0;
    while(fscanf(fptr,"%s %d %[^\n] %f %d %s", products[count].product_name, &products[count].product_code, products[count].product_description, &products[count].product_price, &products[count].product_quantity, products[count].last_update)==6){
        count +=1;
        
    }
    fclose(fptr);
    return count;
    
}

void lowercase_conversion(char user_input[100]){
    for(int i=0;i<strlen(user_input);i++){
        user_input[i]=tolower(user_input[i]);   
    }
}

//case1
//same as user input
void same_as_userinput(product_list products[],int no_of_products, char *user_input, int *case1){
    for(int i =0 ;i<no_of_products;i++){
        char k[100];
        strcpy(k,products[i].product_name);
        lowercase_conversion(k);
        if(strstr(k,user_input)!=NULL){
            *case1 = 1;
            //printf("match was found");
            break; //exits the function once match was found
        }
    }
}             


//case 2
//spelling mistakes liks destol instead dettol
void spelling_mistake(char *user_input,int no_of_products,product_list products[],int *case2, char corrected_input[100]){
    int k=strlen(user_input);
    corrected_input[0] = '\0';// Initialize corrected_input to empty string
    int min_difference=k+1;//intialize with large difference between input and its matches
    for(int i=0;i<no_of_products;i++){
        int len = strlen(products[i].product_name);
        if (len >= k){
            
            for(int j=0; j<=len-k ;j++){
                char substring[k+1];
                int differences=0;
            
                strncpy(substring, &products[i].product_name[j], k);
                substring[k]='\0';
                lowercase_conversion(substring);

                for(int l=0;l<k;l++){
                
                    if (substring[l]!=user_input[l]){
                        differences+=1;
                    }
                
                }
                int tolerence=k/2;
                if (differences < tolerence && differences < min_difference){
                    strcpy(corrected_input,substring);
                    min_difference= differences;
                }
            }
        }
    }
    if (strcmp(corrected_input,user_input)!= 0 && strlen(corrected_input)>0){
        //we use did you mean output 
        *case2 = 2;//for switch()
        //printf("the user input is corrected");
    }
    //else{
       // printf("finding matches for incorrect input was unsuccessful");
    //}
}

void switch_function(int *cases, char *user_input,char *corrected_input, int no_of_products, product_list products[]){
    switch (*cases) {
        case 1:
            //a match
            //printf("A match was found for the input and no correction case1 = 1 case2 =0.\n");
            printf("The products matching with \"%s\":\n",user_input);
            printf("-----------------------------------------------------------------\n");
            printf("%-25s %10s %16s \n","Product name","Price","Quantity");
            printf("-----------------------------------------------------------------\n");
            for(int i =0 ;i<no_of_products;i++){
                char k[100];
                strcpy(k,products[i].product_name);
                lowercase_conversion(k);
                    if(strstr(k,user_input)!=NULL){
             
                        printf("%-25s %10.2f %16d \n",products[i].product_name,products[i].product_price,products[i].product_quantity);
                    }
    
            }
            printf("-----------------------------------------------------------------\n");

            break;
            
        case 2:  
            //printf("no match and the input was corrected case1=0 and case2 = 2.\n");
            
            printf("Did you mean \"%s\"?\n",corrected_input);
            printf("-----------------------------------------------------------------\n");
            printf("%-25s %10s %16s \n","Product name","Price","Quantity");
            printf("-----------------------------------------------------------------\n");
            for(int i =0 ;i<no_of_products;i++){
                char k[100];
                strcpy(k,products[i].product_name);
                lowercase_conversion(k);
                    if(strstr(k,corrected_input)!=NULL){
             
                        printf("%-25s %10.2f %16d \n",products[i].product_name,products[i].product_price,products[i].product_quantity);
                    }
    
            }
            printf("-----------------------------------------------------------------\n");  
                        break;
        case 3:  
            //printf("match found and the input was corrected case1=1 case2=2.\n");
            break;
        case 0:   
            //printf("No exact match or correction found case1 and case2 =0.\n");
            printf("You may be interested in:\n");
            printf("-----------------------------------------------------------------\n");
            printf("%-25s %10s %16s \n","Product name","Price","Quantity");
            printf("-----------------------------------------------------------------\n");
            for (int i=0;i<10 && i< no_of_products ;i++){
                printf("%-25s %10.2f %16d\n",products[i].product_name,products[i].product_price,products[i].product_quantity);
            }
            printf("-----------------------------------------------------------------\n");
            break;
        default:
           // printf("Unknown case.\n");
            break;
    }
}

void giving_products(int no_of_products, char *user_input, int *case1, int *case2, int *cases, char *corrected_input, product_list products[]) {
    lowercase_conversion(user_input);
    *case1 = 0;//each time giving_products is called case1and2 are intialized to 0
    *case2 = 0;

    same_as_userinput(products, no_of_products, user_input, &case1);
    spelling_mistake(user_input, no_of_products, products, &case2, corrected_input);

    *cases = *case1 + *case2;  // Update cases based on the latest values of case1 and case2

    switch_function(&cases, user_input, corrected_input, no_of_products, products);
}

void search (){
    product_list products[productsize_limit];
    char user_input[100];
    char corrected_input[100];
    int no_of_products = counting_product_from_file("records.dat",products);
    if (no_of_products == 0){
        printf("No products available\n");
        return;
    }
   
    int case1 = 0,case2 = 0,cases = 0;

   

    while (1) {

        printf("Please enter the keyword to search: ");
        scanf("%s", user_input);
        giving_products(no_of_products, user_input, &case1, &case2, &cases, corrected_input, products);

        printf("Do you want to \n(a) Search\n(b) Add to Cart\n(c) Exit Search\n");
        printf("Give the option in a, b, c\n");
        char input[100];
        fgets(input, sizeof(input), stdin);
        lowercase_conversion(input);

        if (strcmp(input, "a") == 0) {
            continue;
        } else if (strcmp(input, "b") == 0) {
            add_to_cart();
        } else if (strcmp(input, "c") == 0) {
            printf("Exiting.....\n");
            break;
        } else {
            printf("Invalid input. Please enter a, b, or c.\n");
        }
    }

}
