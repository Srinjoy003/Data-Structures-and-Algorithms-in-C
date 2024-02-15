#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next; 
    struct Node *prev;
};

void Display(struct Node *head)
{
    if (head == NULL)
        printf("Empty Queue");

    else{
        struct Node *p = head;

        while (p != NULL){
            printf("%d ",p -> data);
            p = p -> next;
            
        }
    }
    
    printf("\n");
}


void EnqueueAtFront(struct Node **head,struct Node **rear,int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = *head;
    ptr -> data = data;

    if (*head == NULL){
        *head = ptr;
        *rear = ptr;
        ptr -> next = NULL;
    }
    else{
        ptr -> next = *head;
        p -> prev = ptr;
       *head = ptr;
    }
}
   

void EnqueueAtRear(struct Node **head,struct Node **rear,int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    struct Node *q = *rear;

    if (*rear == NULL){
        *head = ptr;
        *rear = ptr;
        ptr -> prev = NULL;
        ptr -> next = NULL;
    }
    
    else{
        ptr -> next = NULL;
        ptr -> prev = *rear;
        q -> next = ptr;
        *rear = ptr;
    }
}


int DequeueAtFront(struct Node **head,struct Node **rear)
{ 
    
    struct Node *p = *head;
    int x;
    
    if (*head == NULL){
        printf("Underflow");
        return -100;
    }
    
    if (*head == *rear){
        x = p -> data;
        *head = NULL;
        *rear = NULL;
    }

    else{
        x = p -> data;
        *head = p -> next;
        p -> next -> prev = NULL;
        free(p);
        
    }
    printf("Dequeued %d\n",x);
    return x;
}

int DequeueAtRear(struct Node **head,struct Node **rear)
{ 
    
    struct Node *p = *head;
    struct Node *q = *rear;
    int x;
    
    if (*rear == NULL){
        printf("Underflow");
        return -100;
    }
    
    if (*head == *rear){
        x = q -> data;
        *head = NULL;
        *rear = NULL;
    }

    else{
        x = q -> data;
        *rear = q -> prev;
        q -> prev -> next = NULL;
        free(q);
        
    }
    printf("Dequeued %d\n",x);
    return x;
}





int main(){
    struct Node *head = NULL;
    struct Node *rear = NULL;

    int input = 5,data,x,choice;
    
    while(input != 0){
        printf("\n1-Enqueue  2-Dequeue  3-Display 0-Exit\n\n");
        printf("Enter your choice");
        scanf("%d",&input);
        
        if (input == 0){
            break;
        }
        else if (input == 1){
            printf("ENQUEUE : 1 - At Top    2 - At End\n\n");
            printf("Enter Choice :");
            scanf("%d",&choice);

            if (choice == 1){
                printf("AT TOP: Enter the value :");
                scanf("%d",&data);
                printf("\n");
                EnqueueAtFront(&head,&rear,data);
            }
            
            else if (choice == 2){
                printf("AT END: Enter the value :");
                scanf("%d",&data);
                printf("\n");
                EnqueueAtRear(&head,&rear,data);
            }

            else
                printf("\nINVALID CHOICE\n");
        }
        
        else if(input == 2){
            printf("DEQUEUE : 1 - At Top    2 - At End\n\n");
            printf("Enter Choice :");
            scanf("%d",&choice);

            if (choice == 1){
                x = DequeueAtFront(&head,&rear);
            }
            
            else if (choice == 2){
                x = DequeueAtRear(&head,&rear);
            }

            else
                printf("\nINVALID CHOICE\n");
        }
        
        else if(input = 3){
            Display(head);
        
        }
        
        else
            printf("\nInvalid Input");

        
    }

    
    return 0;
}
   
