#include<stdio.h>
#include<stdlib.h>

#define I INT_MAX

struct Node
{
    int data ;
    struct Node *next; 
};

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int arr[][2],int n,int element1,int element2,int* size){ 
    arr[n][0] = element1;
    arr[n][1] = element2;
   
    (*size)++;
    int i,temp1,temp2;
    i = n;
    temp1 = arr[n][0];
    temp2 = arr[n][1];

    int comp = arr[n][1];

    
    while(i > 0 && comp < arr[(i-1)/2][1]){ 
        
        arr[i][0] = arr[(i-1)/2][0];
        arr[i][1] = arr[(i-1)/2][1];
       
        i = (i-1)/ 2;
    }

    arr[i][0] = temp1;
    arr[i][1] = temp2;
   
}



void heapify(int arr[][2],int n,int i){
    int temp;
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    

    if (left < n && arr[left][1] < arr[smallest][1]){
        
        smallest = left;
    }
    if (right < n && arr[right][1] < arr[smallest][1]){
      
        smallest = right;
    }

    if (smallest != i){
        swap(&arr[i][0],&arr[smallest][0]);
        swap(&arr[i][1],&arr[smallest][1]);
        heapify(arr,n,smallest);
    }
}

void delete(int arr[][2],int n,int* size){
    

    swap(&arr[0][0],&arr[n][0]);
    swap(&arr[0][1],&arr[n][1]);

    heapify(arr,n,0);
    (*size)--;
}

void printPath(int parent[], int j, int vertex)
{
    
    if (parent[j] == -1){
        printf("%d => ",j);
        return;
    }

    printPath(parent, parent[j], vertex);

    if (j == vertex)
        printf("%d ", j);
    else    
        printf("%d => ", j);

}





int SP(int cost[][100],int v,int source){

    int i,j;
    
    struct Node* list[v];
    struct Node *ptr;
    int s[v];
    int parent[v];



    for (i = 0; i < v; i++)
    {
        ptr = (struct Node*) malloc(sizeof(struct Node));
        ptr -> next = NULL;
        list[i] = ptr;
      
        s[i] = 0;
        
        for (j = 0; j < v; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] != I)
            {
                ptr -> data = j;
                ptr -> next = (struct Node*) malloc(sizeof(struct Node));
               
                ptr = ptr -> next;
                s[i]++;

            }
            
        }
        printf("\n");

    }
   


    int Q[v][2];
    int visited[v];
    int ans[v];
    
    int size = 0,k = 0,curr;
    
    for(int i = 0;i < v; i++){
        visited[i] = 0;
        ans[i] = I;    // stores final distances
        parent[i] = -1;
        
    }

   

    insert(Q,size,source,0,&size);
    ans[source] = 0;


    

    while (size > 0 ){
       
        
        
        if (visited[Q[0][0]] != 1){
            
            
           
            curr = Q[0][0];
            visited[curr] = 1;
            ptr = list[curr];
            
            delete(Q,size-1,&size);
            
            for(int i = 0;i < s[curr]; i++){
                
               
                int vertex = ptr -> data;
                ptr = ptr -> next;

                if(cost[curr][vertex] != 0 && cost[curr][vertex] != I  && visited[vertex] != 1){
                    int wt = cost[curr][vertex];
                  
                    

                    
                    if (ans[vertex] > ans[curr] + wt){ //relaxation
                        ans[vertex] = ans[curr] + wt;
                        insert(Q,size,vertex,ans[vertex],&size); 
                        parent[vertex] = curr;
                        
                    }
                    
                }
            }
        
        }
        
        else
            delete(Q,size-1,&size);
          
    }

   
    printf("Source Vertex = %d\n\n",source);
    
    for(int i = 1; i < v;i++){
        printf("%d -----%d   ",i,ans[i]);
        printPath(parent, i, i);
        printf("\n");
    }
    printf("\n\n");

    
    
    


}

int main(){
    
    
    
    int cost[][100] =  {{0, 10, I, 5, I}, 
                        {I, 0, 1, 2, I}, 
                        {I, I, 0, I, 4}, 
                        {I, 3, 9, 0, 2}, 
                        {7, I, 6, I, 0}};
    
    SP(cost,5,0);


    return 0;

}


