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

int LinearSearch(int arr[],int size,int element){
    
    for (int i = 0; i < size ;i++){
        if (arr[i] == element)
            return 1;
        
    }
    return 0;


}

struct Node *Reverse(struct Node *head){
    struct Node *p = head;
    struct Node *q = head -> next;
    struct Node *r;

    while (q != NULL){
        r = q -> next;
        q -> next = p;

        if (p == head)
            p -> next = NULL;
     
        p = q;
        q = r;
    }
    return p;


}

struct Node *RecursiveReverse(struct Node **head,struct Node *p,struct Node *q){ //1st attempt
    
    
    
    if (q == NULL) {
        *head = p;
        p -> next = NULL;
    }
    
    else{
        struct Node *r = q -> next;

        if (r == NULL){
            *head = q;
            return p;
        }

        if (p == *head){
            q -> next = p;
            p -> next = NULL;
        }

        r -> next = RecursiveReverse(head,q,r);
        return p;

    }
    



}

/*--------------------------------------------------------------
CHECKS IF LOOP IS PRESENT

ALGORITHM : 1) Takes 2 ptrs - a) slow - Moves 1 step  b) fast - Moves 2 steps 
            2) Both start at head.
            3) If at anytime after the first jump ==> slow == fast ==> LOOP EXISTS
*/
struct Node *CheckLoop (struct Node *head){ //using slow and fast pointer
    struct Node *slow = head;
    struct Node *fast = head;

    int a = 1;
    if (slow -> next == NULL || fast -> next -> next == NULL)
        printf("Loop doesn't exist\n");
        
    else{
        slow = slow -> next;
        fast = fast -> next -> next;
    
        while(a){
            if (slow == fast ){
                printf("Loop exists\n");
                break;
            }
            else if (slow -> next == NULL || fast -> next -> next == NULL){
                printf("Loop doesn't exist\n");
                break;
            }
            slow = slow -> next;
            fast = fast -> next -> next;
        
        }
    }

}

/*--------------------------------------------------------------------------------------------------
CHECKS MERGING POINT OF 2 LINKED LISTS WHICH START AT 2 SEPARATE POINTS BUT MERGE AFTER A POINT

ALGORITHM : 1) Traverse Both Lists  and find the length. O(m) + O(n) = O(max((m,n)))
            2) d = length of larger linked list - length of smaller linked list
            3) Move d steps forward in the larger linked list
            4)Traverse both Lists at the same time(parallel) and compare each node
            5) Match Found == Merging Point
*/
struct Node *MergingPoint(struct Node *head1,struct Node*head2){
    
    int L1 = 0, L2 = 0;
    struct Node *ptr1 = head1;
    struct Node *ptr2 = head2;

    while(ptr1){
        L1++;
        ptr1 = ptr1 -> next;
    }

    while(ptr2){
        L2++;
        ptr2 = ptr2 -> next;
    }

    int d = abs(L1 -L2);
    ptr1 = head1;
    ptr2 = head2;

    if (d > 0){
        while(d){
            if (L1 > L2)
                ptr1 = ptr1 -> next;
            
            else if (L1 < L2)
                ptr2 = ptr2 -> next;
            
            d--;
        }
    }

    ptr1 = head1;
    ptr2 = head2;

    while(ptr1 && ptr2){
        if (ptr1 == ptr2){
            printf("Merges at %d\n",ptr1 -> data);
            return ptr1;
        }
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next;
    }

    printf("No Merging Point\n");
    return;   
        


}

/*---------------------------------------------------------------------------
FINDS MIDDLE NODE OF LINKED LIST

ALGORITTHM : 1) Use a slow pointer(moves 1 step) and a fast pointer(moves 2 steps)
             2) If  fast == NULL(even number of nodes) or fast -> next = NULL(odd number of nodes) ==> STOP
             3) slow will point to the middle 
             Time Complexity = O(n/2) (fastest algorithm)
            
            Can also be used to check whether llinked list has odd or even nodes


*/
struct Node *MiddeNode(struct Node *head){

    struct Node *slow = head;
    struct Node *fast = head;

    while(fast && fast -> next){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

/*------------------------------------------------------------------
PRINT LINKED LIST FROM END
Recursively print the linked list in reverse
*/
void ReversePrint(struct Node *head){
    
    if (head -> next)
        ReversePrint(head -> next);
        printf("%d ",head -> data);


}
int main(){
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));
    fourth = (struct Node*) malloc(sizeof(struct Node));

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = NULL;

    head -> data = 20;
    second -> data = 12;
    third -> data = 16;
    fourth -> data = 5;

    CheckLoop(head);
    //head = Reverse(head);
    RecursiveReverse(&head,head,head -> next);
    PrintList(head);
    printf("\n");
    ReversePrint(head);

    return 0;
}