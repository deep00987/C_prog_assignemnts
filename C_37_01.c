#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 150

typedef struct 
{
    char *name;
    long long int roll;
    double *marks;
    double total_marks;
    double avg_marks;

}Student;


void print_student_data(Student*);
void create_student_entity(Student*);
void swap_student_data(Student*, Student*);

int main(){
    Student **students;
    char *hack;
    int i, j, n;
    printf("\nEnter the No of students: \n");
    scanf("%d", &n);

    // allocate memory
    students = (Student**)malloc(sizeof(Student*) * n);
    for (i = 0; i < n; i++){
        students[i] = (Student*)malloc(sizeof(Student));
    }

    scanf("%c", &hack);
    // create student entity
    for (i = 0; i < n; i++){
        create_student_entity(students[i]);
    }
    // print student data
    for (i = 0; i < n; i++){
        print_student_data(students[i]);
    }

    //sort student data
    for(i = 0; i < n - 1; i++){
        for( j = 0; j < n - i - 1; j++){
            if (students[j]->total_marks < students[j + 1]->total_marks){
                swap_student_data(students[j], students[j + 1]);
            }
        }
    }
    // print student data
    printf("\nSorted Sutdent data by total marks-->\n");
    for (i = 0; i < n; i++){
        printf("Student: ");
        print_student_data(students[i]);
    }

    return 0;
}

void create_student_entity(Student* student){
    int i, sum = 0;
    char hack;
    student->name = (char*)malloc(sizeof(char)*50);
    student->marks = (double*)malloc(sizeof(double) * 5);
    
    printf("\nEnter Student Name:");
    fflush(stdin);
    gets(student->name);
    
    printf("\nEnter Roll Number: ");
    scanf("%lld", &student->roll);

    printf("\nEnter Marks of 5 subjects: ");
    for(i = 0; i < 5; i++){
        scanf("%lf", &student->marks[i]);
        sum += student->marks[i];
    }
    // catch the \n pressed after last input
    scanf("%c", &hack);

    student->total_marks = sum;
    student->avg_marks = sum / (double)5;
}


void print_student_data(Student* student){
    int i;
    printf("{\n");
    printf("  Name: %s, \n", student->name);
    printf("  Roll-No: %lld, \n", student->roll);
    for (i = 0; i < 5; i++){
        printf("  Mark_%d: %.2lf, \n",i + 1, student->marks[i]);
    }
    printf("  Total_marks: %.2lf, \n", student->total_marks);
    printf("  avg_marks: %.2lf \n", student->avg_marks);
    printf("},\n");
}

void swap_student_data(Student *s1, Student *s2){
    char *name = s1->name;
    long long int roll = s1->roll;
    double *marks = s1->marks;
    double total_marks = s1->total_marks;
    double avg = s1->avg_marks;
 
    s1->name = s2->name;
    s1->roll = s2->roll;
    s1->marks = s2->marks;
    s1->avg_marks = s2->avg_marks;
    s1->total_marks = s2->total_marks;
 
 
    s2->name = name;
    s2->roll = roll;
    s2->marks = marks;
    s2->avg_marks = avg;
    s2->total_marks = total_marks;
}