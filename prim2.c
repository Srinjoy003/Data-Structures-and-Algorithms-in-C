#include<stdio.h>
#include<stdlib.h>

#define I INT_MAX

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int arr[][3],int cost[][100],int n,int element1,int element2,int* size){ // last element index after adding element
    arr[n][0] = element1;
    arr[n][1] = element2;
    arr[n][2] = cost[element1][element2];
    
    
    (*size)++;
    int i,temp1,temp2,temp3;
    i = n;
    temp1 = arr[n][0];
    temp2 = arr[n][1];
    temp3 = arr[n][2];
    int comp = arr[n][2];

    
    while(i > 0 && comp < arr[(i-1)/2][2]){ 
        
        arr[i][0] = arr[(i-1)/2][0];
        arr[i][1] = arr[(i-1)/2][1];
        arr[i][2] = arr[(i-1)/2][2];
        i = (i-1)/ 2;
    }

    arr[i][0] = temp1;
    arr[i][1] = temp2;
    arr[i][2] = temp3;
}



void heapify(int arr[][3],int cost[][100],int n,int i){
    int temp;
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    

    if (left < n && arr[left][2] < arr[smallest][2]){
        
        smallest = left;
    }
    if (right < n && arr[right][2] < arr[smallest][2]){
      
        smallest = right;
    }

    if (smallest != i){
        swap(&arr[i][0],&arr[smallest][0]);
        swap(&arr[i][1],&arr[smallest][1]);
        swap(&arr[i][2],&arr[smallest][2]);
        heapify(arr,cost,n,smallest);
    }
}

void delete(int arr[][3],int cost[][100],int n,int* size){ //last element index
    //printf("deleted %d\n",arr[0]);

    swap(&arr[0][0],&arr[n][0]);
    swap(&arr[0][1],&arr[n][1]);
    swap(&arr[0][2],&arr[n][2]);

    heapify(arr,cost,n,0);
    (*size)--;
}

void print(int arr[][3],int size){

    for(int i = 0; i < size; i++)
        printf("%d %d %d\n",arr[i][0],arr[i][1],arr[i][2]);
    printf("\n");
}

int MST(int cost[][100],int v){ //v is no of vertices
    int Q[v][3];
    int visited[v];
    int tree[v][2];
    int size = 0,k = 0;
    
    for(int i = 0;i < v; i++)
        visited[v] = 0;
    
    int curr = 0;
    visited[curr] = 1;
    
    for(int i = 0;i < v; i++){
        if(cost[curr][i] != I && cost[curr][i] != 0  && visited[i] != 1){
            insert(Q,cost,size,i,curr,&size); // new vertex in 0 index
        }
    }


    while (size > 0 ){
        if (visited[Q[0][0]] != 1){
            tree[k][0] = Q[0][0];
            tree[k][1] = Q[0][1];
            //printf("%d -----%d----- %d \n",tree[k][0]+1,cost[tree[k][0]][tree[k][1]],tree[k][1]+1);
            k++;
            curr = Q[0][0];
            visited[curr] = 1;
            delete(Q,cost,size-1,&size);
            
            for(int i = 0;i < v; i++){
                if((cost[curr][i] != I && cost[curr][i] != 0)  && visited[i] != 1)
                    insert(Q,cost,size,i,curr,&size); // new vertex in 0 index
            }
        
        }
        
        else{
            delete(Q,cost,size-1,&size);
            continue;
        }
    }

    int sum = 0;
    for(int i = 0; i < v-1;i++){
        sum += cost[tree[i][0]][tree[i][1]];
        printf("%d -----%d----- %d \n",tree[i][0]+1,cost[tree[i][0]][tree[i][1]],tree[i][1]+1);
    }
    printf("\ntotal cost = %d",sum);
            
    


}

int main(){
    /*int cost[][100] = {{I,25,I,I,I,5,I},
                        {25,I,12,I,I,I,10},
                        {I,12,I,8,I,I,I},
                        {I,I,8,I,16,I,14},
                        {I,I,I,16,I,20,18},
                        {5,I,I,I,20,I,I},
                        {I,10,I,14,18,I,I}};*/
    
    int cost[][100] = {{0,4,I,I,I,I,I,8,I},
                        {4,0,8,I,I,I,I,11,I},
                        {I,8,0,7,I,4,I,I,2},
                        {I,I,7,0,9,14,I,I,I},
                        {I,I,I,9,0,10,I,I,I},
                        {I,I,4,14,10,0,2,I,I},
                        {I,I,I,I,I,2,0,1,6},
                        {8,11,I,I,I,I,1,0,7},
                        {I,I,2,I,I,I,6,7,0}};
    int n = 0;
    int arr[100][3];
    MST(cost,9);
    /*insert(arr,cost,n,3,2,&n);
    insert(arr,cost,n,5,4,&n);
    insert(arr,cost,n,2,7,&n);
    insert(arr,cost,n,6,5,&n);
    delete(arr,cost,n-1,&n);
    delete(arr,cost,n-1,&n);
    delete(arr,cost,n-1,&n);
    delete(arr,cost,n-1,&n);*/
    //print(arr,n);
    
    /*delete(arr,n-1,&n);
    delete(arr,n-1,&n);
    delete(arr,n-1,&n);
    delete(arr,n-1,&n);*/
    return 0;

}


