#include<stdio.h>
#include<stdlib.h>

#define I INT_MAX

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int l_partition(int arr[][3],int low,int high){

    int pivot = arr[high][2];
    int i = low - 1;
    int j;
    char temp;
    

    for (j = low; j < high ; j++ ){

        
        if (arr[j][2] <= pivot){
            i++;
           
            swap(&arr[i][0],&arr[j][0]);
            swap(&arr[i][1],&arr[j][1]);
            swap(&arr[i][2],&arr[j][2]);

        }
        
    }
    swap(&arr[i+1][0],&arr[high][0]);
    swap(&arr[i+1][1],&arr[high][1]);
    swap(&arr[i+1][2],&arr[high][2]);
    return i + 1;
}

void l_QuickSort(int arr[][3],int low,int high){

    if (high > low){

        int mid = l_partition(arr,low,high);
        l_QuickSort(arr,low,mid-1);
        l_QuickSort(arr,mid+1,high);
    }
}

void Union(int s[],int u,int v){
    
    if (s[u] < s[v]){
        s[u] += s[v];
        s[v] = u;
    }

    else{
        s[v] += s[u];
        s[u] = v;
    }
}

int Find(int s[],int u){
    
    while(s[u] > 0)
        u = s[u];
    return u;
}

void MST(int cost[][100],int n){ 

    int i,j,e = 0,min,u,v,k = 0;
    int edges[100][3];
    int set[n];
    int tree[n][2];
    

    for(i = 0; i < n;i++)
        set[i] = -1;
       

    for(i = 0; i < n;i++){
        for(j = i; j < n;j++){
                if (cost[i][j] != 0 && cost[i][j] != I){
                    edges[e][0] = i;
                    edges[e][1] = j;
                    edges[e][2] = cost[i][j];
                    
                    e++;
                }

        }
    }

    

    i = 0;
    
    l_QuickSort(edges,0,e-1);

    while (i < n-1){
     
        u = edges[k][0];
        v = edges[k][1];


        if (Find(set,u) != Find(set,v)){
            tree[i][0] = u;
            tree[i][1] = v;
            Union(set,Find(set,u),Find(set,v));
            i++;

        }
        //included[k] = 1;
        k++;

    }

    int sum = 0;

    printf("\n\n");
    for(int i = 0; i < n-1;i++){
        sum += cost[tree[i][0]][tree[i][1]];
        printf("%d -----%d----- %d \n",tree[i][0]+1,cost[tree[i][0]][tree[i][1]],tree[i][1]+1);
    }
    printf("\ntotal cost = %d\n\n",sum);

}
int main(){
    int cost[][100] = {{0,4,I,I,I,I,I,8,I},
                        {4,0,8,I,I,I,I,11,I},
                        {I,8,0,7,I,4,I,I,2},
                        {I,I,7,0,9,14,I,I,I},
                        {I,I,I,9,0,10,I,I,I},
                        {I,I,4,14,10,0,2,I,I},
                        {I,I,I,I,I,2,0,1,6},
                        {8,11,I,I,I,I,1,0,7},
                        {I,I,2,I,I,I,6,7,0}};
    
    
    MST(cost,9);
  
    return 0;

}