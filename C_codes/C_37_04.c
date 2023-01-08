#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dd;
    int mm;
    int yyyy;
}Date;

int compare_dates(Date*, Date*);
void get_input(Date*);
void display_date(Date*);



int main(){
    Date *d1, *d2;
    
    int res = 0; 

    d1 = (Date*)malloc(sizeof(Date));
    d2 = (Date*)malloc(sizeof(Date));

    printf("\nEnter Date 1:\n");
    get_input(d1);
    printf("\nEnter Date 2:\n");
    get_input(d2);

    printf("\nInput 1: \n");
    display_date(d1);
    printf("\nInput 2: \n");
    display_date(d2);

    res = compare_dates(d1, d2);
    
    if (res == 1){
        printf("\nGiven dates are equal\n");
    }else{
        printf("\nGiven dates not equal\n");

    }

    return 0;
}


void get_input(Date* date){
    printf("\nEnter day: ");
    scanf("%d", &date->dd);
    if (date->dd > 31 && date->dd < 1){
        printf("\nEntered Invalid value, Exiting ...\n");
        exit(1);
    }
    printf("\nEnter month: ");
    scanf("%d", &date->mm);
    if (date->mm > 12 && date->mm < 1){
        printf("\nEntered Invalid value, Exiting ...\n");
        exit(1);
    }
    printf("\nEnter year: ");
    scanf("%d", &date->yyyy);
    if (date->yyyy > 9999){
        printf("\nEntered Invalid value, Exiting ...\n");
        exit(1);
    }
}

void display_date(Date* date){
    printf("\ndate is: %d/%d/%d \n", date->dd, date->mm, date->yyyy);
}

int compare_dates(Date *d1, Date *d2){
    if (d1->dd != d2->dd){
        return 0;
    }
    if (d1->mm != d2->mm){
        return 0;
    }
    if (d1->yyyy != d2->yyyy){
        return 0;
    }
    return 1;
}


