#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>



#define I0 INT_MIN
#define I1 INT_MAX
#define MAX_LEVEL 4

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

int rand_level() { //generates random no of levels less than MAX_LEVEL for the new node to be inserted
    int level = 0;
    while (rand() < RAND_MAX / 2 && level < MAX_LEVEL)
        level++;
    return level;
}

struct Node* CreateNode(int key,int level){ 
    int i;
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr -> forward = (struct Node**)malloc(sizeof(struct Node*) * (level+1));
    
    ptr ->  key = key;
     
    //memset(ptr -> forward, 0, sizeof(struct Node*) * (level+1)); //
    for( i = 0; i < level + 1; i++) //initialise forward array as null
        ptr -> forward[i] = NULL;

   

    return ptr;
}

struct SkipList* skiplist_init(struct SkipList *list) { //creates skiplist
    int i;
    list = (struct SkipList*) malloc(sizeof(struct SkipList));
    struct Node* head = CreateNode(I0,MAX_LEVEL);
    list -> level = 0;
    list -> head = head;
    return list;
    
}


struct SkipList* Insert(struct SkipList* list,int key){
    
    int i;
    struct Node* curr = list -> head;
    struct Node* update[MAX_LEVEL + 1];

    for( i = 0; i < MAX_LEVEL + 1; i++) //initialise update array as null
        update[i] = NULL;
    
    
    int level = list -> level;

    for(i = level; i >= 0; i--){ // for vertical traversal

        while (curr -> forward[i] != NULL && curr -> forward[i] -> key < key) // for horizontal traversal
            curr = curr -> forward[i];

        update[i] = curr; //insert the node at ith level after which the new node is to be inserted at that level
    }

    curr = curr -> forward[0]; // at level 0 ,move one pointer to the right where the new node is to be inserted

    int rand_lvl = rand_level(); 

    if (rand_lvl > level){

        for (i = level + 1; i < rand_lvl + 1; i++)
            update[i] = list -> head; // adds new levels if rand_lvl > list->level

        list -> level = rand_lvl; //update the list's current level
    }

    struct Node* new = CreateNode(key,rand_lvl); // create new node
    

    for (i = 0; i <= rand_lvl; i++){ // insert node by rearranging pointers

        new -> forward[i] = update[i] -> forward[i]; // 1 -> 2 -> 4 ==> 1 -> 2 -> 4   3 -> 4 attaches 3(new) to 4
        update[i] -> forward[i] = new;// 1 -> 2 -> 3 -> 4 attaches 2 to 3
    }
    printf("Inserted %d\n",key);
    
    return list;
    
}

struct Node* Search(struct SkipList* list, int key){

    int i, level = list -> level;
    struct Node* curr = list -> head;
    

    for(i = level; i >= 0; i--){ // for vertical traversal

        while (curr -> forward[i] != NULL && curr -> forward[i] -> key < key) // for horizontal traversal
            curr = curr -> forward[i];
    }

    curr = curr -> forward[0]; 

    if (curr && curr -> key == key){
        printf("Found Key %d\n",key);
        return curr;

    }

    else{
        printf("NOt Found Key %d\n",key);
        return NULL;

    }



}

struct SkipList* Delete(struct SkipList* list, int key){

    int i, level = list -> level;
    struct Node* curr = list -> head;
    struct Node* update[MAX_LEVEL + 1];

    for( i = 0; i < MAX_LEVEL + 1; i++) //initialise update array as null
        update[i] = NULL;
    
    for(i = level; i >= 0; i--){ // for vertical traversal

        while (curr -> forward[i] != NULL && curr -> forward[i] -> key < key)
            curr = curr -> forward[i];
        
        update[i] = curr; 
    }
    curr = curr -> forward[0]; // same as insert operation ,saves the pointer before key at each level

    if (curr != NULL && curr -> key == key){

        for (i = 0; i <= level; i++){
            
            if (update[i] -> forward[i] != curr)
                break;

            update[i] -> forward[i] = curr -> forward[i]; // removes the node at each level

            
        }

        while (level > 0 && list -> head -> forward[level] == NULL) //updates level of skiplist
            level--;
        list -> level = level;

        printf("Deleted %d\n",key);
    }

    else    
        printf("Key to be deleted NOT FOUND\n");


    return list;




}




void displayList(struct SkipList* list)
{
    int i, level = list -> level;
    printf("*****Skip List*****\n");
    struct Node* ptr;
    
	for(i = level; i >= 0; i--)
	{
		ptr = list -> head -> forward[i];
	
        //printf("Level %d: ",i);

		while(ptr)
		{
            printf("%d ",ptr->key);
			ptr = ptr->forward[i];
		}
		printf("\n");
	}
    printf("\n");
}




int main(){

    struct SkipList* list;
    
    list = skiplist_init(list);

    

    list = Insert(list,1);
    list = Insert(list,2);
    list = Insert(list,3);
    list = Insert(list,4);
    displayList(list);

    
   






    




 
    

    return 0;
}