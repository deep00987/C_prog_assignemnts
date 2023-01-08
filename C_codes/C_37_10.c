#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFF_SIZE 1024
#define FILE_NAME "./c_37_10_student_records.csv"

typedef struct{
    char name[50];
    int roll;
    float marks;
    char dob[20];
}Student;


void add_new_record(FILE*, Student*);
void delete_record_by_roll(int);
void modify_marks(FILE*);


int main(){
    FILE *file_ptr;
    Student *s1;
    int choice;
    s1 = (Student*)malloc(sizeof(Student));
    

    while (1){
        printf("\nEnter 1 to add a new record.");
        printf("\nEnter 2 to delete a record by roll no.");
        printf("\nEnter 3 to modify marks of the students.");
        printf("\nEnter any other keys to exit.\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                file_ptr = fopen(FILE_NAME, "ab");
                add_new_record(file_ptr, s1);
                break;
            case 2:
                int roll;
                printf("\nEnter roll-no of the student: ");
                scanf("%d", &roll);
                delete_record_by_roll(roll);
                break;
            case 3:
                file_ptr = fopen(FILE_NAME, "rb");
                modify_marks(file_ptr);
                break;
            default:
                printf("\nExiting .... \n");
                exit(1);
        }

    }

    return 0;
}


void modify_marks(FILE* file_ptr){
    FILE *file_ptr_tmp;
    file_ptr_tmp = fopen("./c_37_10_student_records_tmp.csv", "wb");
    
    if (file_ptr == NULL || file_ptr_tmp == NULL){
        printf("\nError occured opening file\n");
        fclose(file_ptr_tmp);
        remove("./c_37_10_student_records_tmp.csv");
        return;
    }

    char line[MAX_BUFF_SIZE];
    char line_tok[MAX_BUFF_SIZE];
    char *token, data[4][50];

    int i;
    double marks;
    char marks_str[20];

    while (fgets(line, MAX_BUFF_SIZE, file_ptr)){
        strcpy(line_tok, line);
        token = strtok(line_tok, ",");
        i = 0;
        while (token != NULL){
            strcpy(data[i], token);
            token = strtok(NULL, ",");
            i++;
        }
        marks = strtod(data[2], NULL);
        if (marks >= 40 && marks < 50){
            marks += 10;
        }
        sprintf(marks_str, "%0.2f", marks);
        printf("%s   ", marks_str);
        
        strcpy(line_tok, data[0]);
        strcat(line_tok, ",");
        strcat(line_tok, data[1]);
        strcat(line_tok, ",");
        strcat(line_tok, marks_str);
        strcat(line_tok, ",");
        strcat(line_tok, data[3]);
        

        fputs(line_tok, file_ptr_tmp);
    }

    fclose(file_ptr);
    fclose(file_ptr_tmp);
    remove(FILE_NAME);
    rename("./c_37_10_student_records_tmp.csv", FILE_NAME);
}


void delete_record_by_roll(int roll_no){
    FILE *file_ptr, *file_ptr_tmp;
    file_ptr = fopen(FILE_NAME, "rb");
    file_ptr_tmp = fopen("./c_37_10_student_records_tmp.csv", "wb");
    
    if (file_ptr == NULL || file_ptr_tmp == NULL){
        printf("\nError occured opening file\n");
        fclose(file_ptr_tmp);
        remove("./c_37_10_student_records_tmp.csv");
        return;
    }

    int flag = 0;
    char line[MAX_BUFF_SIZE];
    char line_tok[MAX_BUFF_SIZE];

    char *token, roll[20];
    while (fgets(line, MAX_BUFF_SIZE, file_ptr)){
        strcpy(line_tok, line);
        token = strtok(line_tok, ",");
        
        sprintf(roll, "%d", roll_no);

        if (strcmp(roll, token) == 0){
            flag = 1;
            continue;
        }
        fputs(line, file_ptr_tmp);
        
    }

    if(!flag){
        printf("No match found!");
    }
    fclose(file_ptr);
    fclose(file_ptr_tmp);
    remove(FILE_NAME);
    rename("./c_37_10_student_records_tmp.csv", FILE_NAME);
}

void add_new_record(FILE *file_ptr, Student *student){
    fflush(stdin);
    char hack, buffer[MAX_BUFF_SIZE], marks_str[20], roll_str[20];
    scanf("%c", &hack);
    printf("\nEnter Student Name: ");
    gets(student->name);
    printf("\nEnter Student Roll-no: ");
    scanf("%d", &student->roll);
    printf("\nEnter Student marks: ");
    scanf("%f", &student->marks);
    scanf("%c", &hack);
    printf("\nEnter Student date of birth: ");
    gets(student->dob);

    sprintf(roll_str, "%d", student->roll);
    sprintf(marks_str, "%0.2f", student->marks);

    printf("\nname: %s", student->name);
    printf("\nroll-no: %s", roll_str);
    printf("\nmarks: %s", marks_str);
    printf("\ndob: %s", student->dob);
    
    
    strcpy(buffer, roll_str);
    strcat(buffer, ",");
    strcat(buffer, student->name);
    strcat(buffer, ",");
    strcat(buffer, marks_str);
    strcat(buffer, ",");
    strcat(buffer, student->dob);
    strcat(buffer, "\n");

    fputs(buffer, file_ptr);
    fclose(file_ptr);
    
}

