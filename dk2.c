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

void print(int arr[][2],int size){

    for(int i = 0; i < size; i++)
        printf("%d %d \n",arr[i][0]+1,arr[i][1]);
    printf("\n");
}





int SP(int cost[][100],int v,int source){
   


    int Q[v][2];
    int visited[v];
    int ans[v];
    
    int size = 0,k = 0,curr;
    
    for(int i = 0;i < v; i++){
        visited[i] = 0;
        ans[i] = I; // stores final distances
        
    }

   

    insert(Q,size,source,0,&size);
    ans[source] = 0;


    


    while (size > 0 ){
        print(Q,size);
        for(int i = 0;i < v; i++)
            printf("%d ",ans[i]);

        printf("\n\n\n");
    
        
        if (visited[Q[0][0]] != 1){
            
            
           
            curr = Q[0][0];
            visited[curr] = 1;
            
            delete(Q,size-1,&size);
            
            for(int i = 0;i < v; i++){
                if(cost[curr][i] != 0 && cost[curr][i] != I  && visited[i] != 1){
                    int wt = cost[curr][i];
                    

                    
                    if (ans[i] > ans[curr] + wt){ //relaxation
                        ans[i] = ans[curr] + wt;
                        insert(Q,size,i,ans[i],&size); 
                    }
                    
                }
            }
        
        }
        
        else
            delete(Q,size-1,&size);
          
    }

   
   
    for(int i = 0; i < v;i++){
        printf("%d -----%d \n",i+1,ans[i]);
    }
    
    
    


}

int main(){
    int i,j;
    
    /*int cost[][100] ={{0, 4, I, I, I, I, I, 8, I},
                        {4, 0, 8, I, I, I, I, 11, I},
                        {I, 8, 0, 7, I, 4, I, I, 2},
                        {I, I, 7, 0, 9, 14, I, I, I},
                        {I, I, I, 9, 0, 10, I, I, I},
                        {I, I, 4, 14, 10, 0, 2, I, I},
                        {I, I, I, I, I, 2, 0, 1, 6},
                        {8, 11, I, I, I, I, 1, 0, 7},
                        {I, I, 2, I, I, I, 6, 7, 0}};*/
    
    int cost[][100] =  {{I, 25, I, I, I, 5, I},
                        {25, I, 12, I, I, I, 10},
                        {I, 12, I, 8, I, I, I},
                        {I, I, 8, I, 16, I, 14},
                        {I, I, I, 16, I, 20, 18},
                        {5, I, I, I, 20, I, I},
                        {I, 10, I, 14, 18, I, I}};
    
    /*int cost[][100] =  {{0, 10, I, 5, I}, 
                        {I, 0, 1, 2, I}, 
                        {I, I, 0, I, 4}, 
                        {I, 3, 9, 0, 2}, 
                        {7, I, 6, I, 0}};*/
    
    SP(cost,7,0);

    
    
    // find errors in this code

    return 0;

}


