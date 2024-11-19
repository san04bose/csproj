#include <stdio.h>
#include <string.h>
#include <time.h>
#include "my_functions.h"
#include <ctype.h>
#define TRUE 1


void registerAdmin(){
    FILE *fp;
    admin mrx;
    char numlist[15] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '%', '$', '@', '#', '*'};

    fp = fopen("admin.dat", "a+");
    int i, j, f = 0;

    while (1) {
        printf("Give valid name\n");
        fgets(mrx.name, sizeof(mrx.name), stdin);
        // Remove the newline character
        mrx.name[strcspn(mrx.name, "\n")] = '\0';
        
        for (i = 0; i < 14; i++) {
            for (j = 0; j < strlen(mrx.name); j++) {
                if (numlist[i] == mrx.name[j]) {
                    f = 1;
                    
                    
                }
                
            }
        }

        if(f == 1){
            printf("Not valid name\n");
            continue;;
        }
        else{
            break;
        }
        
    }

    while (1) {
        printf("Give age\n");
        if (scanf("%d", &mrx.age) == 1) {
            if (mrx.age > 18 && mrx.age < 100) {
                while (getchar() != '\n');

                break;
            }
        }
    }

    while (1) {
        printf("Give valid password\n");
        fgets(mrx.password, sizeof(mrx.password), stdin);
        mrx.password[strcspn(mrx.password, "\n")] = '\0';  // Remove the newline
        if(strlen(mrx.password)<6 || strlen(mrx.password)>10){
            printf("Give password within 6 to 10 digits");
            continue;
        }
        
        else{
            break;
        }
        
    }

    while (1) {
        printf("Give email\n");
        fgets(mrx.email, sizeof(mrx.email), stdin);
        mrx.email[strcspn(mrx.email, "\n")] = '\0';
        
        if (strchr(mrx.email, '@') && strchr(mrx.email, '.')) {
            break;  // Email is valid
        }
        else{
            printf("Invalid email. Please enter a valid email address.\n");
            continue;
        }
    }

    while (1) 
{
        printf("Give mobile number: ");
        fgets(mrx.mobile, sizeof(mrx.mobile), stdin);
        mrx.mobile[strcspn(mrx.mobile, "\n")] = '\0'; // yaha se fgets() se aaya newline remove karne ke liye this statement is important 

        int valid = 1;
        if (strlen(mrx.mobile) != 10) valid = 0; //yaha length check kar rahe hai 
        for (int i = 0; i < strlen(mrx.mobile); i++) {
            if (!isdigit(mrx.mobile[i])) valid = 0; //  yaha par checking if they are digits only or not
        }
        if (valid) break;
        printf("Re enter.\n");
    }

    
    fwrite(&mrx, sizeof(mrx), 1, fp);
    fclose(fp);
    printf("Registered successfully\n");

}





void registerUser(){
    FILE *fp;
    user mrx;
    char numlist[15] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '%', '$', '@', '#', '*'};

    fp = fopen("user.dat", "a+");
    int i, j, f = 0;

    while (1) {
        printf("Give valid name\n");
        fgets(mrx.name, sizeof(mrx.name), stdin);
        // Remove the newline character
        mrx.name[strcspn(mrx.name, "\n")] = '\0';
        
        for (i = 0; i < 14; i++) {
            for (j = 0; j < strlen(mrx.name); j++) {
                if (numlist[i] == mrx.name[j]) {
                    f = 1;
                    
                    
                }
                
            }
        }

        if(f == 1){
            printf("Not valid name\n");
            continue;;
        }
        else{
            break;
        }
        
    }

    while (1) {
        printf("Give age\n");
        if (scanf("%d", &mrx.age) == 1) {
            if (mrx.age > 18 && mrx.age < 100) {
                while (getchar() != '\n');

                break;
            }
        }
    }

    while (1) {
        printf("Give valid password\n");
        fgets(mrx.password, sizeof(mrx.password), stdin);
        mrx.password[strcspn(mrx.password, "\n")] = '\0';  // Remove the newline
        if(strlen(mrx.password)<6 || strlen(mrx.password)>10){
            printf("Give password within 6 to 10 digits");
            continue;
        }
        
        else{
            break;
        }
        
    }

    while (1) {
        printf("Give email\n");
        fgets(mrx.email, sizeof(mrx.email), stdin);
        mrx.email[strcspn(mrx.email, "\n")] = '\0';
        
        if (strchr(mrx.email, '@') && strchr(mrx.email, '.')) {
            break;  // Email is valid
        }
        else{
            printf("Invalid email. Please enter a valid email address.\n");
            continue;
        }
    }

    while (1) 
{
        printf("Give mobile number: ");
        fgets(mrx.mobile, sizeof(mrx.mobile), stdin);
        mrx.mobile[strcspn(mrx.mobile, "\n")] = '\0'; // yaha se fgets() se aaya newline remove karne ke liye this statement is important 

        int valid = 1;
        if (strlen(mrx.mobile) != 10) valid = 0; //yaha length check kar rahe hai 
        for (int i = 0; i < strlen(mrx.mobile); i++) {
            if (!isdigit(mrx.mobile[i])) valid = 0; //  yaha par checking if they are digits only or not
        }
        if (valid) break;
        printf("Re enter.\n");
    }

    
    fwrite(&mrx, sizeof(mrx), 1, fp);
    fclose(fp);
    printf("Registered successfully\n");
}




int loginAdmin(){
    int p = 0;
    admin mrx;
    char email[20];
    char password[10];
    FILE *fp;

    fp = fopen("admin.dat", "r");
    if (!fp) {
        printf("Error: Unable to open the file.\n");
        return 0;
    }

    printf("Give email:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline character

    printf("Give password:\n");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character

    // Read user data and check credentials
    while (fread(&mrx, sizeof(user), 1, fp) == 1) {
        if (strcmp(mrx.email, email) == 0) {
            if (strcmp(mrx.password, password) == 0) {
                printf("Welcome to Runtime Terror!\n");
                p = 1; // Login successful
                break;
            } else {
                printf("Invalid password. Try again.\n");
                p = 2; // Password mismatch
                break;
            }
        }
    }

    if (p == 0) {
        printf("Invalid email. Please register first.\n");
    }

    fclose(fp);
    return p;
}

int loginUser(){
    int p = 0;
    user mrx;
    char email[20];
    char password[10];
    FILE *fp;

    fp = fopen("user.dat", "r");
    if (!fp) {
        printf("Error: Unable to open the file.\n");
        return 0;
    }

    printf("Give email:\n");
    fgets(email, sizeof(email), stdin);
    email[strcspn(email, "\n")] = '\0'; // Remove newline character

    printf("Give password:\n");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // Remove newline character

    // Read user data and check credentials
    while (fread(&mrx, sizeof(user), 1, fp) == 1) {
        if (strcmp(mrx.email, email) == 0) {
            if (strcmp(mrx.password, password) == 0) {
                printf("Welcome to Runtime Terror!\n");
                p = 1; // Login successful
                break;
            } else {
                printf("Invalid password. Try again.\n");
                p = 2; // Password mismatch
                break;
            }
        }
    }

    if (p == 0) {
        printf("Invalid email. Please register first.\n");
    }

    fclose(fp);
    return p;

}

void add_stocks(stocks new_stock) {
    printf("Enter item name: \n");
    fgets(new_stock.name, sizeof(new_stock.name), stdin);
    new_stock.name[strcspn(new_stock.name, "\n")] = '\0'; // Remove trailing newline

    printf("Enter code of stocks: \n");
    while (scanf("%d", &new_stock.code) != 1) {
        printf("Invalid input. Please enter an integer: \n");
        while (getchar() != '\n'); // Clear the input buffer
    }// Remove trailing newline

    printf("Enter description: \n");
    fgets(new_stock.desc, sizeof(new_stock.desc), stdin);
    new_stock.desc[strcspn(new_stock.desc, "\n")] = '\0'; // Remove trailing newline

    printf("Enter number of stocks: \n");
    while (scanf("%d", &new_stock.no_stocks) != 1) {
        printf("Invalid input. Please enter an integer: \n");
        while (getchar() != '\n'); // Clear the input buffer
    }
    getchar();
    printf("Enter price of stocks: \n");
    while (scanf("%f", &new_stock.price) != 1) {
        printf("Invalid input. Please enter float price: \n");
        while (getchar() != '\n'); // Clear the input buffer
    }
    getchar(); 

    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    strcpy(new_stock.last_update, asctime(ptr));
    new_stock.last_update[strcspn(new_stock.last_update, "\n")] = '\0'; // Remove newline

    FILE *fpt = fopen("records.dat", "a+");
    if (fpt == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&new_stock, sizeof(new_stock), 1, fpt);
    fclose(fpt);

    printf("Stock added successfully!\n");
}

void remove_stocks(char item_name[100]){
    FILE *fpt;
    FILE *fp;
    stocks item;
    fp = fopen("records.dat", "r");
    if (fp == NULL) {
    perror("Error opening file");
    return;
}
    fpt = fopen("temp.dat", "w");
    if (fpt == NULL) {
    perror("Error opening file");
    return;
}
    rewind(fp);
    while(fread(&item, sizeof(item), 1, fp)==1){
        if(strcmp(item.name, item_name) != 0){
            fwrite(&item, sizeof(item), 1, fpt);
        }
        
        }
    fclose(fp);
    fclose(fpt);
    remove("records.dat");
    rename("temp.dat", "records.dat");
    printf("removed succesfully");
}

    

    

int add_to_cart(char item_name[20], int units){
    FILE *fpt;
    FILE *fpt2; 
    stocks item;
    cart new_item;
    int f = 0;
    fpt2 = fopen("records.dat", "a+");
    if (fpt == NULL) {
    perror("Error opening file");}
    fpt = fopen("Your_cart.dat", "a+");
    if (fpt == NULL) {
    perror("Error opening file");
    }

    while(fread(&item, sizeof(item), 1, fpt2)){
        if(strcmp(item.name, item_name) == 0){ 
            strcpy(new_item.name, item.name);
            strcpy(new_item.code,item.code);
            new_item.units = units;
            new_item.available_units = item.no_stocks;
            new_item.total_price = units*item.price;
            fwrite(&new_item, sizeof(new_item), 1, fpt);
            fclose(fpt);
            f = 1;
            float tot_price = buy();
    	    if (tot_price != -1) {
            bill(tot_price);
                
        }
        
    }
    return f;
} 
}


float buy(){
    FILE *fp;
    FILE *fp2;
    FILE *fpt;
    FILE *fpt2;
    cart i;
    stocks j;
    float tot_price = 0;
    
    fp = fopen("Your_cart.dat", "w+");
    if (fp == NULL) {
    perror("Error opening file");
    
}
    fp2 = fopen("records.dat", "w+");
    if (fp2 == NULL) {
    perror("Error opening file");
 
    
}
    fpt2 = fopen("TEMP.dat", "w+");
    if (fpt2 == NULL) {
    perror("Error opening file");}
    rewind(fp);
    rewind(fp2);
    while(fread(&i, sizeof(i), 1, fp)==1){
        tot_price += i.total_price;
        rewind(fp2);
        while(fread(&j, sizeof(j), 1, fp2)==1){
            if(strcmp(i.name, j.name) != 1){
                fwrite(&j, sizeof(j), 1, fpt2);
        }
            else{
                j.no_stocks -= i.units;
                if(j.no_stocks > 0){
                    fwrite(&j, sizeof(j), 1, fpt2);
                }
            }
        }
    }
    fclose(fp);
    fclose(fp2);
    fclose(fpt2);
    remove("Your_cart.dat");
    remove("records.dat");
    rename("TEMP.dat", "records.dat");
    printf("\n Your total price is %f", tot_price);
    return tot_price;
} 
    


void remove_from_cart(char item_name[20]){
    FILE *fpt;
    FILE *fpt2;
    cart i;
    fpt2 = fopen("temp.dat", "a+");
    if (fpt2 == NULL) {
    perror("Error opening file");
    
}
    fpt = fopen("Your_cart.dat", "a+");
    if (fpt == NULL) {
    perror("Error opening file");
    
}
    rewind(fpt);
    while(fread(&i, sizeof(i), 1, fpt)==1){
        if(strcmp(i.name, item_name) != 0){
            fwrite(&i, sizeof(i), 1, fpt2);
        }
        
        }
    fclose(fpt2);
    fclose(fpt);
    remove("Your_cart.dat");
    rename("temp.dat", "Your_cart.dat");
    }

float bill(float total_price){
    float deli_fee = 0;
    int city;
    int d;
    printf("To collect from store press 1. Press 2 for delivery.");
    scanf("%d", &d);
    if(d==1){
        printf("Collect from store. Here is your bill.");
    }
    else if(d==2){
        printf("\nChoose the given number for a city from the list: \n Kolkata: 1 ; deli_fee = 10  \n Hooghly : 2 ; deli_fee = 20\n Arkham : 3 ; deli_fee = 30\n Atlantis : 3 ; deli_fee = 40\n");
        scanf("%d", &city);
        if(total_price > 200){
        deli_fee = 0;
        }
        else{
         while(1){ 
            switch(city){
                case 1 : deli_fee = 10;
                                break;
                case 2 : deli_fee = 20;
                                break;
                case 3 : deli_fee = 30;
                                break;
                case 4 : deli_fee = 40;
                                break;
                default : printf("Given city is out of our reach");
                            continue;
            }
        }
    }
    }
    else{
        printf("Enter a valid number.");
    }
    

    
    
    float tax = 0.15*total_price;
    float dis;
    if(total_price > 150){
        dis = 0.1*total_price;
    }
    else if(total_price > 250){
        dis = 0.2*total_price;
    }
    else if(total_price > 500){
        dis = 0.4*total_price;
    }
    else{
        dis = 0;
    }

    total_price = total_price - dis + deli_fee + tax;
    int a;
    printf("Payment Methods:\n 1.press '1' for cash on Delivery \n 2. press '2' for UPI payment  \n 3. press '3 for Net Banking\n'");
    scanf("%d",&a);
    while(1){
    switch(a)
    {
        case 1:printf("Keep your Cash ready!!!\n");
              
                break;
        case 2:printf("UPI link");
                break;
        default : printf("Choose a valid method");
                    continue;        
    }
    }
    time_t t=time(NULL);
    struct tm date=*localtime(&t);
    printf("Your order is confirmed!\n");
    printf("Your total price %f", total_price);
    printf("Time of Order:%1ld",t);
    printf("Date of Order:%d-%02d-%02d", date.tm_year+1900,date.tm_mon+1,date.tm_mday);
    printf("You can cancel your order within 48 hours");
    return total_price;

}

// Chatbot function that encapsulates the interaction logic
void chatbot(Product *products, int size) {
    char input[100];
    greet();
    showHelp();
    while (1) {
        printf("\nYou: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0; // Remove trailing newline
        toLowerCase(input); // Convert input to lowercase
        
        if (strcmp(input, "exit") == 0) {
            printf("Chatbot: Goodbye!\n");
            break;
        } else if (strcmp(input, "help") == 0) {
            showHelp();
        } else if (strcmp(input, "search") == 0) {
            searchProduct(products, size);
        } else if (strcmp(input, "faq") == 0) {
            faq();
        } else if (strcmp(input, "sortby price") == 0) {
            sortProductsByPrice(products, size);
        } else {
            printf("Chatbot: I didn't understand that command. Type 'help' for assistance.\n");
        }
        printf("Chatbot: Please enter your next command.\n");
    }
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Greet the user
void greet() {
    printf("Chatbot: Welcome to our e-commerce platform! How can I assist you today?\n");
}

// Show help commands
void showHelp() {

    printf("Chatbot: You can use the following commands:\n");
    printf("  - help: Show this help message\n");
    printf("  - search: Search for a product\n");
    printf("  - faq: Get answers to frequently asked questions\n");
    printf("  - sortby price: Sort products by price\n"); 
    printf("  - exit: Exit the chat\n");
}

// Function to load products from a file
int loadProducts(char *filename, Product* products) {
    FILE *fptr;
    fptr = fopen(filename,"r");
    if (fptr==NULL){
        printf("Error in loading the products\n");
        exit(1);
    }
    int count = 0;
    while(fscanf(fptr,"%s %d %s %f %d %s", products[count].name, &products[count].code, products[count].description, &products[count].price, &products[count].units, products[count].last_update)==6){
        count +=1;
        
    }
    fclose(fptr);
    return count;
    
}

// Function to search for products by substring
void searchProduct(Product *products, int size) {
    char productName[max_name];
    printf("Chatbot: Enter the product name to search: ");
    
    // Read the input using fgets to handle spaces and newline
    fgets(productName, sizeof(productName), stdin);
    productName[strcspn(productName, "\n")] = '\0'; // Remove trailing newline
    
    toLowerCase(productName); // Convert productName to lowercase
    
    int found = 0;
    for (int i = 0; i < size; i++) {
        char lowerName[max_name];
        strncpy(lowerName, products[i].name, max_name); // Safely copy product name
        toLowerCase(lowerName); // Convert product name to lowercase for comparison
        
        // Check if the product name contains the search string
        if (strstr(lowerName, productName) != NULL) {
            if (!found) {
                printf("Chatbot: Products found:\n");
            }
            
            printf("Name: %s\n", products[i].name);
            printf("Code: %d\n", products[i].code); // Corrected format specifier
            printf("Description: %s\n", products[i].description);
            printf("Price: %.2f\n", products[i].price);
            printf("Units: %d\n", products[i].units);
            printf("\n");
            found = 1;
        }
    }
    if (found == 0) {
        printf("Chatbot: No products found containing '%s'.\n", productName);
    }
}

// Function to display FAQs
void faq() {
    char question[256];
    while (1) {
        printf("Chatbot: What is your question about? (type 'exit faq' to stop)\n");
        printf("You: ");
        fgets(question, sizeof(question), stdin);
        question[strcspn(question, "\n")] = 0; // Remove trailing newline
        toLowerCase(question); // Convert question to lowercase
        
        if (strcmp(question, "exit faq") == 0) {
            printf("Chatbot: Exiting FAQ section.\n");
            break;
        }

        if (strstr(question, "create account") != NULL) {
            printf("Chatbot: You can create an account by clicking on the 'Sign Up' button on the home page.\n");
        } else if (strstr(question, "payment methods") != NULL) {
            printf("Chatbot: We accept credit/debit cards, UPI and bank transfers.\n");
        } else if (strstr(question, "track my order") != NULL) {
            printf("Chatbot: You can track your order by logging into your account and visiting the 'Orders' section.\n");
        } else if (strstr(question, "return policy") != NULL) {
            printf("Chatbot: We offer a 30-day return policy for unused items in their original packaging.\n");
        } else if (strstr(question, "reset my password") != NULL) {
            printf("Chatbot: To reset your password, click on the 'Forgot Password' on the login page and follow the instructions.\n");
        } else if (strstr(question, "shipping options") != NULL) {
            printf("Chatbot: We offer various shipping options. Shipping costs and times vary depending on the option you choose.\n");
        } else if (strstr(question, "cancel or modify my order") != NULL) {
            printf("Chatbot: Yes, you can cancel or modify your order within 24 hours of placing it. Please contact our customer support team for assistance.\n");
        } else if (strstr(question, "contact customer support") != NULL) {
            printf("Chatbot: You can contact our customer support team via email at support@ecommerce.com.\n");
        } else {
            printf("Chatbot: I'm sorry, I don't have an answer for that question. Please try asking something else or type 'help' for assistance.\n");
        }
    }
}

// Function to sort products by price using bubble sort
void sortProductsByPrice(Product *products, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if (products[j].price > products[j + 1].price) {
                // Swap the products
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }
    // Print sorted products
    printf("Chatbot: Products sorted by price:\n");
    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", products[i].name);
        printf("Code: %d\n", products[i].code);
        printf("Description: %s\n", products[i].description);
        printf("Price: %.2f\n", products[i].price);
        printf("Units: %d\n", products[i].units);
        printf("\n");
    }
}





//search algorithm
int counting_product_from_file(char *product_file, product_list* products){
    FILE *fptr;
    fptr = fopen(product_file,"r");
    if (fptr==NULL){
        printf("Error in loading the products\n");
        exit(1);
    }
    int count = 0;
    while(fscanf(fptr,"%s %d %s %f %d %s", products[count].product_name, &products[count].product_code, products[count].product_description, &products[count].product_price, &products[count].product_quantity, products[count].last_update)==6){
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
//spelling mistakes liks destol
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
            printf("Available products\n");
            printf("-----------------------------------------------------------------\n");
            printf("%-25s %10s %16s \n","Product name","Price","Quantity");
            printf("-----------------------------------------------------------------\n");
            for (int i=0;i<no_of_products;i++){
                printf("%-25s %10.2f %16d\n",products[i].product_name,products[i].product_price,products[i].product_quantity);
            }
            printf("-----------------------------------------------------------------\n");
            break;
        default:
           // printf("Unknown case.\n");
            break;
    }
}

void search(int no_of_products, char *user_input, int *case1, int *case2, int *cases, char *corrected_input, product_list products[]) {
    lowercase_conversion(user_input);

    same_as_userinput(products, no_of_products, user_input, case1);
    spelling_mistake(user_input, no_of_products, products, case2, corrected_input);

    *cases = *case1 + *case2;  // Update cases based on the latest values of case1 and case2

    switch_function(cases, user_input, corrected_input, no_of_products, products);
}
