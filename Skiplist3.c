#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


#define I0 INT_MIN
#define I1 INT_MAX
#define MAX_LEVEL 10

struct Node
{
    int key;
    struct Node** forward; //stores the pointers of the nodes corresponding to this node on each level
};

struct SkipList //for each level of SkipList
{
    int level; //current level of skipList
    struct Node* head;
};

int rand_level() { //CHANGE LATER
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
        level++;
    return level;
}

struct Node* CreateNode(int key,int level){
    int i;
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    struct Node* forward[level+1];

    for( i = 0; i < level + 1; i++) //initialise forward array as null
        forward[i] = NULL;

    ptr ->  key = key;
    ptr -> forward = forward;

    return ptr;
}

struct SkipList* Insert(struct SkipList* list,int key){
    printf("inserting\n");
    int i;
    struct Node* current = list -> head;
    struct Node* update[MAX_LEVEL + 1];
    
    for( i = 0; i < MAX_LEVEL + 1; i++) //initialise update array as null
        update[i] = NULL;
    
    printf("inserting2\n");


    for(i = list -> level; i >= 0; i--){ // for vertical traversal

        while (current -> forward[i] != NULL && current -> forward[i] -> key < key) // for horizontal traversal
            current = current -> forward[i];

        
        update[i] = current; //insert the node at ith level after which the new node is to be inserted at that level
        printf("%d\n",i);
    }

    current = current -> forward[0]; // at level 0 ,move one pointer to the right where the new node is to be inserted

    printf("inserting3\n");
    

    int rand_lvl = rand_level();

    if (rand_lvl > list -> level){

        for (i = list -> level + 1; i < rand_lvl + 1; i++)
            update[i] = list -> head; // adds new levels

        list -> level = rand_lvl; //update the list's current level


    }
    printf("inserting4\n");

    struct Node* new = CreateNode(key,rand_lvl); // create new node
    printf("inserting5\n");

    for (i = 0; i <= rand_lvl; i++){ // insert node by rearranging pointers

        new -> forward[i] = update[i] -> forward[i]; // 1 -> 2 -> 4 ==> 1 -> 2 -> 4   3 -> 4 attaches 3(new) to 4
        update[i] -> forward[i] = new;// 1 -> 2 -> 3 -> 4 attaches 2 to 3
    }
    printf("%d\n",new->key);
    return list;

}

void displayList(struct SkipList* list)
{
    int i;
    printf("\n*****Skip List*****\n");
    struct Node* ptr;
    
	for(i = list -> level; i >= 0; i--)
	{
		ptr = list -> head -> forward[i];
	
        printf("Level %d: ",i);

		while(ptr != NULL)
		{
            printf("%d ",ptr->key);
			ptr = ptr->forward[i];
		}
		printf("\n");
	}
}
/*struct Node* Search(struct Node* head,int x){

    struct Node *ptr = head;

    while (1){


        if(ptr  == NULL){ //
            return ptr;
        }

        else if (ptr -> next -> data == x){ // match
            printf("Found %d\n",x);
            return ptr -> next;
        }

        else if (ptr -> next -> data > x){ //go down
         
            if (ptr -> below  == NULL){
                printf("Not Found\n");
                return ptr;
            }

            else
                ptr = ptr -> below;
            
        }

        else if (ptr -> next -> data < x){ // go next
            if (ptr -> next -> data  == I1){
                return ptr;
                printf("Not Found\n");
            }
            
            else
                ptr = ptr -> next;
            
        }



    }
}*/



int main(){

    struct SkipList* list = (struct SkipList*) malloc(sizeof(struct SkipList));

    list -> level = 0;
    list -> head = CreateNode(I0,MAX_LEVEL);

    list = Insert(list,1);
    if (list -> head -> forward[0] == NULL)
        printf("NULL\n");
    printf("inserted %d",list -> head -> forward[0] -> key);

    //displayList(list);

    return 0;
}