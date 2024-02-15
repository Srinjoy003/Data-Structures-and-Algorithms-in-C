#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>



int Enqueue(int arr[],int *start,int *end,int size,int data){

    if (*end == size - 1){
        printf("Oveflow\n");
    }
    else{
        (*end)++;
        arr[*end] = data;
       
        
    }


}

int Dequeue(int arr[],int *start ,int *end,int size){

    if (*end < *start || *end == -1){
        printf("Underflow\n");
    }
    else{
        //printf("Dequeued %d\n",arr[*start]);
        int x = arr[*start];
        (*start)++;
        return x;
        

        
    }
    

}


void QueueDisplay(int arr[],int start,int end){
    for (int i = start;i <= end ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void DFS(int u,int A[][8],int n,int *count){
    static int visited[8] = {0,0,0,0,0,0,0,0};
    if (visited[u] == 0){
        printf("%d ",u);
        visited[u] = 1;
    

        for (int v = 1; v <= n;v++){
            if (A[u][v] == 1 && visited[v] == 0)
                DFS(v,A,n,count);
            
            else if(A[u][v] == 1 && visited[v] == 1)
                (*count)++;
        }
       
    }

    

    
    
}

void BFS(int A[][8],int u,int n){
    int start = 0,end = -1,size = 100;
    int queue[size];
    int visited[] ={0,0,0,0,0,0,0,0};
    printf("%d ",u);
    visited[u] = 1;
    Enqueue(queue,&start,&end,size,u);
    

    while(end >= start && end != -1){
        u = Dequeue(queue,&start,&end,size);

        for(int v = 1;v <= n;v++){
            if (A[u][v] == 1 && visited[v] == 0){
                printf("%d ",v);
                visited[v] = 1;
                Enqueue(queue,&start,&end,size,v);
            }
        }
    }

}

int main(){
    int A[8][8] = {{0,0,0,0,0,0,0,0},
                   {0,0,1,1,1,0,0,0},
                   {0,1,0,1,0,0,0,0},
                   {0,1,1,0,1,1,0,0},
                   {0,1,0,1,0,1,0,0},
                   {0,0,0,1,1,0,1,1},
                   {0,0,0,0,0,1,0,0},
                   {0,0,0,0,0,1,0,0}};
    
    int visited[] = {0,0,0,0,0,0,0,0};
    int count = 0;
    DFS(1,A,7,&count);
    printf("\n%d",count);

    /*int q[10];
    int start = 0,end = -1,size = 10;
    Enqueue(q,&start,&end,size,2);
    Enqueue(q,&start,&end,size,11);
    int x = Dequeue(q,&start,&end,size);
    QueueDisplay(q,start,end);
    printf("%d",x);*/
    
}
