#include <stdio.h>
#include <stdlib.h>

typedef struct Time{
    int hh;
    int mm;
    int ss;
}Time;


Time* add_times(Time*, Time*);
void get_input(Time*);
void display_time(Time*);

int main(){

    Time *t1, *t2, *t3;

    t1 = (Time*)malloc(sizeof(Time));
    t2 = (Time*)malloc(sizeof(Time));
    
    printf("\nEnter Time 1:\n");
    get_input(t1);
    printf("\nEnter Time 2:\n");
    get_input(t2);

    printf("\nInput 1: \n");
    display_time(t1);
    printf("\nInput 2: \n");
    display_time(t2);

    t3 = add_times(t1, t2);
    printf("\nAfter Adding 2 Times --> \n");
    display_time(t3);

    return 0;
}

void get_input(Time* time){
    printf("\nEnter Hour: ");
    scanf("%d", &time->hh);
    if (time->hh > 59){
        printf("\nEntered Invalid value, Exiting ...\n");
        exit(1);
    }
    printf("\nEnter Min: ");
    scanf("%d", &time->mm);
    if (time->mm > 59){
        printf("\nEntered Invalid value, Exiting ...\n");
        exit(1);
    }
    printf("\nEnter Sec: ");
    scanf("%d", &time->ss);
    if (time->ss > 59){
        printf("\nEntered Invalid value, Exiting ...\n");
        exit(1);
    }
}

void display_time(Time* time){
    printf("\nTime is: %d hr %d min %d sec\n", time->hh, time->mm, time->ss);
}

Time* add_times(Time* t1, Time *t2){
    Time *t3;
    t3 = (Time*)malloc(sizeof(Time));

    t3->hh = 0;
    t3->mm = 0;
    t3->ss = 0;
    
    t3->ss = t1->ss + t2->ss;
    if (t3->ss > 59){
        t3->mm += 1;
        t3->ss = t3->ss - 60;
    }
    t3->mm += t1->mm + t2->mm;
    if (t3->mm > 59){
        t3->hh += 1;
        t3->mm = t3->mm - 60;
    }
    t3->hh += t1->hh + t2->hh;
    
    return t3;
}

