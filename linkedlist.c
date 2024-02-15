#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data ;
    struct Node *next; 
};

struct Node* PrintList(struct Node *ptr)
{
    while (ptr != NULL){
        printf("%d ",ptr -> data);
        ptr = ptr -> next;
    }
}


struct Node* insertAtStart(struct Node *head,int data)
{
    struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> data = data;
    ptr -> next = head;
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
    struct Node *p = head;
    struct Node *q = head -> next;
    int i = 0;

    while (i < index - 1){ 
        q =  q -> next; // q is at index
        p = p -> next; // p is at index-1
    }


    p -> next = q -> next; // connects p to q next
    free(q);
    return head;

}

struct Node* DeleteAtEnd(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head -> next;

    while (q -> next != NULL){ //q is last node
        p = p -> next;
        q = q -> next;
    }


   
    p -> next = NULL;
    free(q);
    return head;

}

struct Node* DeleteValue(struct Node *head,int value)
{
   
    
    if (head -> data == value){
        struct Node *ptr = head;
        head = head -> next;
        free(ptr);
    }
    struct Node *p = head;
    struct Node *q = head -> next;
    while (q -> next != NULL){ //q is last node
        if (q -> data == value){
            p -> next = q -> next;
            struct Node *ptr = q;
            q = q -> next;
            free(ptr);
            
        }
        p = p -> next;
        q = q -> next;
    
        
    }
    //if (q -> data == value && q -> next == NULL){
    
    p -> next == NULL;
    free(q);
    

 
   
   
    return head;

}

struct Node* deleteKey(struct Node* head, int x,int max_index)
{
    if (!head)
        return head;
    // Until the head data is equal to the key move the head
    // pointer
    while (head && head->data == x){
        head = head->next;
        max_index--;
    }
    struct Node *q = head, *p = NULL;
    while (q) {
        if (q->data == x){
            p->next = q->next;
            max_index--;
        }
        else
            p = q;
        q = q->next;
    }
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

    /*head -> next = second;
    second -> next = third;
    third -> next = NULL;

    head -> data = 12;
    second -> data = 12;
    third -> data = 16;

    head = insertAtStart(head,12);
    //head = DeleteAtStart(head);

    head = insertAtIndex(head,30,1);
    //head = DeleteAtIndex(head,1);

    head = insertAtEnd(head,50);
    //head = DeleteAtEnd(head);

    PrintList(head);
    printf("\n");
   
    head = DeleteValue(head,12);
    // = DeleteAtEnd(head);
    PrintList(head);*/
 
    int input = 4,max_index = 0,value,data,insert,index,created = 0;

    while (input != 0){
        printf("\n1 - Create Linked List  2 - Insert 3 - Delete  4 - print Linked List 0 - Exit");
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
            printf("\n1 - At Start      2 - At Middle\n\n");
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
                if (index == max_index + 1){
                    head = insertAtEnd(head,data);
                    max_index++;

                }
                else if (index > max_index + 1){
                    printf("\ninvalid index\n");
                }
                else if(index > 0 && index <= max_index){
                    head = insertAtIndex(head,data,index); 

                }
            }
            else{
                printf("invalid choice\n");
            }
        }
        else if (input == 3){
            printf("\n\nEnter the value");
            scanf("%d",&value);
            head = deleteKey(head,value,max_index);
            
            
        }
        else if (input == 4){
               PrintList(head);
        }
    
        PrintList(head);
    }
    return 0;
}












    
