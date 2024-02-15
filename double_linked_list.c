#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next; 
    struct Node *prev;
};

struct Node* PrintList(struct Node *ptr)
{
    while (ptr != NULL){
        printf("%d ",ptr -> data);
        ptr = ptr -> next;1 
    }
    printf("\n");
}


struct Node* insertAtStart(struct Node *head,int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
    head -> prev = ptr;
    ptr -> prev = NULL;
    return ptr;

}


struct Node* insertAtIndex(struct Node *head,int data,int index)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = head; //used to traverse linked list
    int i = 0;
    
    while (i < index - 1){
        p = p -> next;
        i++;


    }
    ptr -> next = p -> next;  //p is at index-1 and ptr is after p
    p -> next = ptr;          // now ptr is at index
    ptr -> prev = p;
    ptr -> next -> prev = ptr;
    ptr -> data = data;
    return head;

}    

struct Node* insertAtEnd(struct Node *head,int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p -> next != NULL){ //p is last node
        p = p -> next;
    }


    ptr -> data = data;
    p -> next = ptr;
    ptr -> next = NULL;
    ptr -> prev = p;
    return head;

}

struct Node* DeleteAtStart(struct Node *head)
{
    struct Node *ptr = head;
    head = head -> next;
    free(ptr);
    return head;
}


struct Node* DeleteAtIndex(struct Node *head,int index)
{
    struct Node *q = head -> next;
    int i = 0;

    while (i < index - 1){ 
        q =  q -> next; // q is at index
        i++;
    }


    q -> prev -> next = q -> next; // connects node before q to q next
    q-> next -> prev = q -> prev;
    free(q);
    return head;

}

struct Node* DeleteAtEnd(struct Node *head)
{
    struct Node *q = head -> next;

    while (q -> next != NULL){ //q is last node
        q = q -> next;
    }


   
    q -> prev -> next = NULL;
    free(q);
    return head;

}






int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    
    head -> data = -10;
    head -> next = NULL;
    

 
    int input = 4,max_index = -1,value,data,insert,index,created = 0,delete;

    while (input != 0){
        printf("\n1 - Create Linked List   2 - Insert   3 - Delete   4 - Print Linked List   0 - Exit\n");
        printf("\nEnter Choice : ");
        scanf("%d",&input);
        if (input == 1){
            if (created == 0){
                printf("Linked List Created\n");
                created = 1;
            }
            else{
                printf("Linked  List Already Created\n");
            }
        }
        else if (input == 2){
            printf("\n1 - At Start      2 - At Middle   3 - At End\n\n");
            printf("Enter choice :");
            scanf("%d",&insert);
            printf("\nEnter the element");
            scanf("%d",&data);
            if (insert == 1){
                if (head -> data == -10){
                    head -> data = data;
                    max_index++;
                }
                else{
                    head = insertAtStart(head,data);
                    max_index++;
                }
            }
            
            
            else if (insert == 2){
                printf("\nEnter Index:\n\n");
                scanf("%d",&index);

               
                if (index > max_index  || index <= 0){
                    printf("\ninvalid index\n");
                }
                else if(index > 0 && index <= max_index){
                    head = insertAtIndex(head,data,index); 
                    max_index++;

                }
            }
            else if (insert == 3){
                head = insertAtEnd(head,data);
                max_index++;

            }
            else{;
                printf("invalid choice\n");
            }
        }
        else if (input == 3){
            printf("\n1 - At Start      2 - At Middle   3 - At End\n\n");
            printf("Enter choice :");
            scanf("%d",&delete);
       

            if (delete == 1){
                if (max_index >= 0){
                    head = DeleteAtStart(head);
                    max_index--;
                }
                    
            }
            
            
           else if (delete == 3){
                if (max_index >= 1){
                    head = DeleteAtEnd(head);
                    max_index--;
                }
            }

            else if (delete == 2){
                printf("\nEnter Index:\n\n");
                scanf("%d",&index);
                
               
                if (index >= max_index  || index <= 0){
                    printf("\ninvalid index\n");
                }
                else if(index > 0 && index < max_index){
                    head = DeleteAtIndex(head,index);
                    max_index--; 


                }
            }

            else{
                printf("invalid choice\n");
            }
        }
        else if (input == 4){
               PrintList(head);
        }
        
    
        
    }
    return 0;
}