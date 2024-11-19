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

    printf("Enter item code: \n");
    fgets(new_stock.code, sizeof(new_stock.code), stdin);
    new_stock.code[strcspn(new_stock.code, "\n")] = '\0'; // Remove trailing newline

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
    fp = fopen("records.dat", "r+");
    if (fp == NULL) {
    perror("Error opening file");
    return;
}
    fpt = fopen("temp.dat", "r+");
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
            
                
        }
        
    }
    return f;
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

int search(char user_in[20])
{
    FILE *fp;
    stocks e;
    int f = 0;
    fp = fopen("records.dat", "r");
    while(fread(&e, sizeof(e), 1, fp)==1){
        if(strstr( e.name, user_in) != NULL){
            f++;
            printf("Product name : %s\n Product code: %s", e.name, e.code);
        }
    }
    if(f == 0){
        printf("no products matched.");
    }

    return f;
}

