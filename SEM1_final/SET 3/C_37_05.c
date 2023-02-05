#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 512

typedef struct{
  int accession_number;
  char *title;
  char *author;
  float price;
  int issued;
}Library;

int book_count = 0;

void add_book_info(Library**);
void display_book_information(Library**);
void list_books_by_author(Library **);
void list_given_book_title(Library **);
void list_all_by_order(Library **);
void swap_elements(Library*, Library*);

int main(){
    int i, choice;
    char hack;
    Library **books;
    books = (Library**)malloc(sizeof(Library*) * MAX_BOOKS);
    for (i = 0; i < MAX_BOOKS; i++){
        books[i] = (Library*)malloc(sizeof(Library));
    }

    while (1){
        printf("\npress 1 Add book information");
        printf("\npress 2 Display book information");
        printf("\npress 3 List all books of given author");
        printf("\npress 4 List the title of specified book");
        printf("\npress 5 List the count of books in the library");
        printf("\npress 6 List the books in the order of accession number");
        printf("\npress 7 or any other key to exit ...\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                add_book_info(books);
                scanf("%c", &hack);
                break;
            case 2:
                display_book_information(books);
                scanf("%c", &hack);
                break;
            case 3:
                list_books_by_author(books);
                // scanf("%c", &hack);
                break;
            case 4:
                list_given_book_title(books);
                break;
            case 5:
                printf("Total book count: %d", book_count);
                break;
            case 6:
                list_all_by_order(books);
                break;
            default:
                printf("\nExiting ....\n");
                exit(1);
        }
    }

    return 0;
}

void add_book_info(Library **book){
    char *hack;
    if (book_count == MAX_BOOKS) {
        printf("Error: Library is full.\n");
        return;
    }

    printf("Enter accession number: ");
    scanf("%d", &book[book_count]->accession_number);
    scanf("%c", &hack);
    
    book[book_count]->title = (char*)malloc(sizeof(char)*50);
    printf("Enter title: ");
    gets(book[book_count]->title);
    
    book[book_count]->author = (char*)malloc(sizeof(char)*50);
    printf("Enter author: ");
    gets(book[book_count]->author);
    
    
    printf("Enter price: ");
    scanf("%f", &book[book_count]->price);

    book[book_count]->issued = 0;
    book_count++;
    printf("Book added successfully.\n");
}


void display_book_information(Library **book) {
  int accession_number;
  printf("Enter accession number: ");
  scanf("%d", &accession_number);

  for (int i = 0; i < book_count; i++) {
        if (book[i]->accession_number == accession_number) {
            printf("Accession number: %d\n", book[i]->accession_number);
            printf("Title: %s\n", book[i]->title);
            printf("Author: %s\n", book[i]->author);
            printf("Price: %.2f\n", book[i]->price);
            printf("Issued: %s\n", book[i]->issued ? "Yes" : "No");
            return;
        }
  }

  printf("Book not found.\n");
}

void list_books_by_author(Library **book)
{
    char author[50], *hack;
    scanf("%c", &hack);
    printf("Enter author: ");
    gets(author);

    int found = 0;
    for (int i = 0; i < book_count; i++)
    {
        if (strcmp(book[i]->author, author) == 0)
        {
            printf("\n----- Book found of given auther -----\n");
            printf("Accession number: %d\n", book[i]->accession_number);
            printf("Title: %s\n", book[i]->title);
            printf("Author: %s\n", book[i]->author);
            printf("Price: %.2f\n", book[i]->price);
            printf("Issued: %s\n", book[i]->issued ? "Yes" : "No");
            found = 1;
        }
    }

    if (!found)
    {
        printf("No books found by that author.\n");
    }
}

void list_given_book_title(Library **book){
    int accession_number;
    printf("Enter accession number: ");
    scanf("%d", &accession_number);
    for (int i = 0; i < book_count; i++) {
        if (book[i]->accession_number == accession_number) {
            printf("\nBook found having assession no %d \n", accession_number);    
            printf("Title: %s\n", book[i]->title);
            return;
        }
    }
    printf("Book doesnt exist.\n");
}

void list_all_by_order(Library **book){
    int i, j;
    for(i = 0; i < book_count - 1; i++){
        for( j = 0; j < book_count - i - 1; j++){
            if (book[j]->accession_number > book[j + 1]->accession_number){
                swap_elements(book[j], book[j + 1]);
            }
        }
    }
    printf("\nBook listing by order of the accession no -----\n");
    for (i = 0; i < book_count; i++)
    {
        printf("Accession number: %d\n", book[i]->accession_number);
        printf("Title: %s\n", book[i]->title);
        printf("Author: %s\n", book[i]->author);
        printf("Price: %.2f\n", book[i]->price);
        printf("Issued: %s\n", book[i]->issued ? "Yes" : "No");
    }

}

void swap_elements(Library *book1, Library *book2){
    int accession_number = book1->accession_number;
    char *title = book1->title;
    char *author = book1->author;
    float price = book1->price;
    int issued = book1->issued;
 
    book1->accession_number = book2->accession_number;
    book1->title = book2->title;
    book1->author = book2->author;
    book1->price = book2->price;
    book1->issued = book2->issued;
    
    book2->accession_number = accession_number;
    book2->title = title;
    book2->author = author;
    book2->price = price;
    book2->issued = issued;
}