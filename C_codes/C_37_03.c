#include <stdio.h>
#include <stdlib.h>

typedef struct{
    long long int acc_no;
    char *name;
    double balance;

}Customer;


void create_customer_entity(Customer*);
void print_customer_data(Customer*);
void print_broke_customers(Customer**, int);
void deposite_withdraw(Customer**, int, int);


int main(){
    Customer **customers;
    char *hack;
    int i, choice, n;
    printf("\nEnter the No of customers: \n");
    scanf("%d", &n);

    // allocate memory
    customers = (Customer**)malloc(sizeof(Customer*) * n);
    for (i = 0; i < n; i++){
        customers[i] = (Customer*)malloc(sizeof(Customer));
    }

    scanf("%c", &hack);
    // create customer entity
    for (i = 0; i < n; i++){
        create_customer_entity(customers[i]);
    }
    // print customer data
    printf("\nShowing all customer data available --> \n");
    for (i = 0; i < n; i++){
        print_customer_data(customers[i]);
    }
    print_broke_customers(customers, n);
    // deposite_withdraw(customers, n);
    while (1){
        printf("\npress 0 to withdraw by giving account info\n");
        printf("\npress 1 to deposit by giving account info\n");
        printf("\npress any other key to exit ...\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0:
                deposite_withdraw(customers, n, 0);
                break;
            case 1:
                deposite_withdraw(customers, n, 1);
                break;
            default:
                printf("\nExiting ....\n");
                exit(1);
        }
    }
    return 0;
}


void create_customer_entity(Customer* customer){
    char hack;
    customer->name = (char*)malloc(sizeof(char)*50);
    
    printf("\nEnter Account Number: ");
    scanf("%lld", &customer->acc_no);
    // catch the \n pressed after last input
    scanf("%c", &hack);

    printf("\nEnter Customer Name:");
    fflush(stdin);
    gets(customer->name);

    printf("\nEnter Balance: ");
    scanf("%lf", &customer->balance);

    // catch the \n pressed after last input
    scanf("%c", &hack);

}

void print_customer_data(Customer* customer){
    printf("{\n");
    printf("  Account-No: %lld, \n", customer->acc_no);
    printf("  Name: %s, \n", customer->name);
    printf("  Balance: %.2lf, \n", customer->balance);
    printf("},\n");
}

void print_broke_customers(Customer** customers, int n){
    int i;
    printf("\nCustomers with balance below 1000 ---------\n"); 
    for (i = 0; i < n; i++){
        if (customers[i]->balance < 1000){
            printf("\nBlance below 100 -->\n");
            print_customer_data(customers[i]);
        }
    }

}


void deposite_withdraw(Customer** customers, int n, int code){
    char hack;
    long long int acc_no;
    double amount;
    int index = -1, i;
    printf("\nEnter Account no, amount: ");
    scanf("%lld %lf", &acc_no, &amount);

    for (i = 0; i < n; i++){
        if (customers[i]->acc_no == acc_no){
            index = i;
        }
    }
    if (index == -1){
        printf("\nNo customer is associated with given account no\n");
        return;
    }

    if (code == 0){
        if (customers[index]->balance < amount){
            printf("\nThe balance is insufficient for the specified withdrawal\n");
            return;
        }else{
           customers[index]->balance -= amount; 
        }
        printf("Updated customer balance --> %lf", customers[index]->balance);
        printf("\nFull customer info: ----\n");
        print_customer_data(customers[index]);
        return;
    }

    if (code == 1){
        customers[index]->balance += amount;
        printf("Updated customer balance --> %lf", customers[index]->balance);
        printf("\ncustomer details: ----\n");
        print_customer_data(customers[index]);
        return; 
    }

}




