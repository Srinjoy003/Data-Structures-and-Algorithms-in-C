#include<stdio.h>

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
        printf("Dequeued %d\n",arr[*start]);
        (*start)++;
        

        
    }
    //return arr[*start];

}

void Display(int arr[],int start,int end){
    for (int i = start;i <= end ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


int main(){
    int start = 0;
    int end = -1;
    int arr[5];
    int size = 5;
    Display(arr,start,end);
    
    Enqueue(arr,&start,&end,size,5);
    Display(arr,start,end);

    
    Enqueue(arr,&start,&end,size,8);
    Display(arr,start,end);
    Enqueue(arr,&start,&end,size,9);
    Display(arr,start,end);
    Enqueue(arr,&start,&end,size,10);
    Display(arr,start,end);
    Enqueue(arr,&start,&end,size,11);
    Display(arr,start,end);
   

    Dequeue(arr,&start,&end,size);
    Display(arr,start,end);
    Dequeue(arr,&start,&end,size);
    Display(arr,start,end);
    Dequeue(arr,&start,&end,size);
    Display(arr,start,end);
    Dequeue(arr,&start,&end,size);
    Display(arr,start,end);
    Dequeue(arr,&start,&end,size);
    Display(arr,start,end);
    Dequeue(arr,&start,&end,size);

    Dequeue(arr,&start,&end,size);

    //printf("%d %d",start,end);
    return 0;
}