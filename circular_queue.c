#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next; 
};

struct Node* Display(struct Node *head,struct Node *rear)
{
    if (head == NULL)
        printf("Empty Queue");

    else{
        struct Node *p = head;

        while (p ->next != head){
            printf("%d ",p -> data);
            p = p -> next;
            
        }
        printf("%d ",p -> data);
    }
    
    printf("\n");
}



struct Node* Enqueue(struct Node **head,struct Node **rear,int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = *rear;
    ptr -> data = data;
    
    if (*head == NULL){
        *head = ptr;
    }   
    else{
        
        p -> next = ptr;
    }
    *rear = ptr;
    ptr -> next = *head;
    
}



int Dequeue(struct Node **head,struct Node **rear)
{ 
    
    struct Node *p = *head;
    struct Node *q = *rear;
    int x;
    if (p == NULL){
        printf("Underflow");
        return -100;
    }
    
    if (p == q){
        x = p -> data;
        *head = NULL;
        *rear = NULL;

        
        
    }
    else{
        x = p -> data;
        *head = p -> next;
        free(p);
        q -> next = *head;
        
    }
    printf("Dequeued %d\n",x);
    return x;
}




int main(){
    struct Node *head = NULL;
    struct Node *rear = NULL;
    
    int input = 5,data,x;
    while(input != 0){
        printf("\n1-Enqueue  2-Dequeue  3-Display 0-Exit\n\n");
        printf("Enter your choice");
        scanf("%d",&input);
        
        if (input == 0){
            break;
        }
        else if (input == 1){
            printf("Enter the value");
            scanf("%d",&data);
            printf("\n");
            Enqueue(&head,&rear,data);
        }
        else if(input == 2){
            x = Dequeue(&head,&rear);
        }
        
        else if(input = 3){
            Display(head,rear);
        
        }
        
        else
            printf("\nInvalid Input");

        
    }

    
    return 0;
}