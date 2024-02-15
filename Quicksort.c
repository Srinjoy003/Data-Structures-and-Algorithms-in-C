#include<stdio.h>
#include<stdlib.h>





int h_partition(int arr[], int low, int high,int *comp)
{
    int pivot = arr[low];
    int i = low - 1, j = high + 1;
 
    while (1) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
            (*comp)++;
        } while (arr[i] < pivot);
 
        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
            (*comp)++;
        } while (arr[j] > pivot);
 
        // If two pointers met.
        if (i >= j)
            return j;
 
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        
    }
}

int hr_partition(int arr[],int low,int high,int *comp){
    int r = low + (rand() % (high - low + 1));
    int temp = arr[r];
    arr[r] = arr[high];
    arr[high] = temp;
    h_partition(arr,low,high,comp);
    
}

void h_QuickSort(int arr[],int low,int high,int *comp){

    if (high > low){

        int mid = h_partition(arr,low,high,comp);
        h_QuickSort(arr,low,mid,comp);
        h_QuickSort(arr,mid+1,high,comp);
    }
}

void hr_QuickSort(int arr[],int low,int high,int *comp){

    if (high > low){

        int mid = hr_partition(arr,low,high,comp);
        hr_QuickSort(arr,low,mid,comp);
        hr_QuickSort(arr,mid+1,high,comp);
    }
}


void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int l_partition(int* arr,int low,int high,int *comp){

    int pivot = arr[high];
    int i = low - 1;
    int j;
    char temp;
    

    for (j = low; j < high ; j++ ){

        (*comp)++;
        if (arr[j] <= pivot){
            i++;
            swap(&arr[i],&arr[j]);
            

        }
        
    }
    swap(&arr[i+1],&arr[high]);
    return i + 1;
    
}



int lr_partition(int arr[],int low,int high,int *comp){
    int r = low + (rand() % (high - low + 1));
    int temp = arr[r];
    arr[r] = arr[high];
    arr[high] = temp;
    l_partition(arr,low,high,comp);
    
}

void l_QuickSort(int arr[],int low,int high,int *comp){

    if (high > low){

        int mid = l_partition(arr,low,high,comp);
        l_QuickSort(arr,low,mid-1,comp);
        l_QuickSort(arr,mid+1,high,comp);
    }
}




void lr_QuickSort(int *arr,int low,int high,int *comp){

    if (high > low){

        int mid = lr_partition(arr,low,high,comp);
        lr_QuickSort(arr,low,mid-1,comp);
        lr_QuickSort(arr,mid+1,high,comp);
    }
}



void generatePermutation(int str[],const int start, int end,int *comp)  
{  
  int temp;  
  int i,j;  
  for(i = start; i < end-1; ++i){  
    for(j = i+1; j < end; ++j)  
    {  
    //Swapping the string by fixing a character  
        swap(&str[i],&str[j]);
        //Recursively calling function generatePermutation() for rest of the characters  
        generatePermutation(str , i+1 ,end,comp);  
        //Backtracking and swapping the characters again  
        temp = str[i];  
        str[i] = str[j];  
        str[j] = temp;  
    }  
  }  
  //Print the permutations  
 
  for (int x = 0;x < end;x++){
    printf("%d",str[x]);
  }
  printf("\n");  
  (*comp)++;
}  

void permute(int* a, int l, int r,int* n, int* sum, int* comp,FILE* in,FILE* out)
{
    int i;
    if (l == r){
        (*n)++;
        for (int x = 0; x <= r;x++)
            fprintf(in,"%d ",a[x]);
        fprintf(in,"\n");

        l_QuickSort(a,0,r,comp);
        *sum += *comp;

        for (int x = 0; x <= r;x++){
            fprintf(out,"%d ",a[x]);
        }
        fprintf(out,"  comparisons = %d",*comp);

        fprintf(out,"\n");
        *comp = 0;
        
    }

        
    else {
        for (i = l; i <= r; i++) {
            swap((a + l), (a + i));
            permute(a, l + 1, r,n,sum,comp,in,out);
            swap((a + l), (a + i)); 
        }
    }
}


int main(){
    
    int comp = 0,sum = 0,sum1 = 0;
    int n,size;
    /*printf("\n\nEnter the number and size of array : ");
    scanf("%d %d",&n,&size);
    printf("\n\n");

    int arr[100000];
    int low = 0,high = size-1;
    

    FILE *in = fopen("unsorted","w+");
    FILE *out = fopen("sorted","w+");*/

    /*
    for (int i = 0;i < n;i++){
        comp = 0;
        for (int j = 0;j < size; j++){
            arr[j] = j;
            fprintf(in,"%d ",arr[j]);

        }
        fprintf(in,"\n\n");

        lr_QuickSort(arr,low,high,&comp);
        sum += comp;

        for (int j = 0;j < size; j++){
            fprintf(out,"%d ",arr[j]);
        }
        fprintf(out,"  comparisons = %d",comp);
        fprintf(out,"\n\n");
    }
    fprintf(out,"Average Comparisons = %f",(sum/1.0)/n);

    fclose(in);
    fclose(out);

    return 0;*/

    //int n;
    FILE *fp = fopen("input.txt","w+");
    FILE *fr = fopen("output.txt","w+");

    printf("\n\nEnter the size of array : ");
    scanf("%d",&n);

    int left = 0,right = n-1;
    int arr[n];
    
    for (int i = 0 ;i < n; i++)
        arr[i] = i;
    int x = 0;
    int count = 0,perm = 0;

    permute(arr,left,right,&perm,&sum1,&comp,fp,fr);

    fprintf(fr,"\n\nAverage Comparisons : %f",(sum1/1.0)/perm);

    for (int i = 0;i < x;i++){
        for (int j = 0;j < x;j++){
            fscanf(fp,"%d",&arr[j]);
        }
        l_QuickSort(arr,0,3,&sum);

        for (int j = 0;j < x; j++){
            fprintf(fr,"%d ",arr[j]);
            
        }
        fprintf(fr,"\n");
    }
    printf("%d",x);

    

    

    
}