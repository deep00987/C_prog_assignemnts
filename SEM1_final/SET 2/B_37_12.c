#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *next;   
}Node;

void insert_node(Node**);
void delete_node(Node**);
void display_list(Node*);
void search_in_list(Node*);

int main(){
    Node *head = NULL, *newHead = NULL;
    Node *n1, *n2, *n3;
    int i, size;
    
    printf("\nEnter No of nodes to be added\n");
    scanf("%d", &size);

    for (i = 0; i < size; i++){
        insert_node(&head);
    }
    printf("\nThe list values -- \n");
    
    display_list(head);
    
    search_in_list(head);

    delete_node(&head);
    
    display_list(head);

    return 0;
}

void display_list(Node* head){
    Node *temp = head;
    printf("\n\n");
    while (temp != NULL){
        printf("%d ", temp->val);
        temp = temp->next;
    }
}

void insert_node(Node** head){
    Node *temp = *head, *newNode;

    newNode = (Node*)malloc(sizeof(Node));
    printf("\nEnter value of the node: ");
    scanf("%d", &newNode->val);
    
    if (*head == NULL){
        *head = newNode;
        return;
    }

    while (temp->next != NULL){
        temp = temp->next;
    }

    newNode->next = NULL;
    temp->next = newNode;

}

void search_in_list(Node* head){
    Node *temp = head;
    int count = 1, n;

    printf("\nEnter element to search: \n");
    scanf("%d", &n);

    while (temp != NULL){
        if (temp->val == n){
            printf("\nelement found at Node: %d\n", count);
            return;
        }
        count++;
        temp = temp->next;
    }
    printf("\nElement not found in the list\n");
}

void delete_node(Node** head){
    Node *temp = *head, *prev = *head;
    int n, i;
    printf("\nEnter Node to be deleted: \n");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        if (i == 0 && n == 1){
            *head = (*head)->next;
        }else{
            if(i == n - 1 && temp != NULL){
                prev->next = temp->next;
            }else{
                prev = temp;
                if (prev == NULL){
                    break;
                }
                temp = temp->next;
            }
        }
    }
}