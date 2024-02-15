#include<stdio.h>
#include<stdlib.h>

    

void insert(int arr[],int n,int *comp){
    int i,temp;
    i = n;
    temp = arr[n];
    
    while(i > 0 && temp > arr[(i-1)/2]){
        
        arr[i] = arr[(i-1)/2];
        i = (i-1)/ 2;
        (*comp)++;
    }
    (*comp)++;
    arr[i] = temp;
}

void heapify(int arr[],int n,int i,int *comp){
    int temp;
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    *comp += 2;

    if (left < n && arr[left] > arr[largest]){
        
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]){
      
        largest = right;
    }
    if (largest != i){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr,n,largest,comp);
    }
}

void delete(int arr[],int n,int*comp){
    int temp = arr[n];
        arr[n] = arr[0];
        arr[0] = temp;
        heapify(arr,n,0,comp);
}

void heapsort(int arr[],int n,int *comp){
    
    for (int i = 1;i < n;i++)
        insert(arr,i,comp);
    
    for(int i = n-1;i >= 0;i--){
        delete(arr,i,comp);
    }
        
        
}

int main() {
    // Write C code here
    int arr[1000];
    int comp = 0;
    int sum = 0;
    
    for(int x = 0;x < 5;x++){
        comp = 0;
        for (int i = 0;i < 1000;i++){
            arr[i] = rand() % 100 ;
        }
        heapsort(arr,1000,&comp);

        printf("ARRAY %d\n\n",x+1);
        for (int i = 0;i < 1000;i++)
            printf("%d ",arr[i]);
        printf("\n\n\n");
        sum += comp;
    }
    printf("Average Comparisons: %f\n\n\n",sum/5.0);
    
    

    return 0;
}


