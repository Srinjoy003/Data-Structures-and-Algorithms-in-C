#include<stdio.h>

void BubbleSort(int arr[], int size){
    int flag = 1, i, j;
    
    for (i = 0; i < size - 1; i ++){
      
        flag = 1;

        for (j = 0; j < size-i-1; j++){

            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
                    
            }
        }

        if (flag == 1)
          break;
        }
}

void InsertionSort(int arr[], int size){
    
    int i,j,x;

    for (i = 0; i < size ; i++){
      
        j = i - 1;
        x = arr[i];

        while(j > -1 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = x;


    }
}

int Lpartition(int arr[],int low,int high,int *comp){

    int pivot = arr[high];
    int i = low - 1;
    int j,temp;

    for (j = low; j < high ; j++ ){

        if (arr[j] <= pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            (*comp)++;

        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[pivot];
    arr[pivot] = temp;
    return i + 1;
    
}

void QuickSort(int arr[],int low,int high,int *comp){

    if (high > low){

        int mid = partition(arr,low,high,comp);
        QuickSort(arr,low,mid-1,comp);
        QuickSort(arr,mid+1,high,comp);
    }
}


int GetMax(int arr[],int size){
    int max = arr[0];
    for (int i = 0;i < size;i++ ){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}
void CountSort(int arr[],int size){

    int max,i,j;
    max = GetMax(arr,size);
    int C[max+1];
    
    for(i = 0;i<max+1;i++)
        C[i] = 0;
    
    for(i = 0; i < size; i++){
        C[arr[i]]++;
    }

    i = 0,j = 0;

    while(i < max + 1){
        if(C[i] > 0){
            arr[j] = i;
            j++;
            C[i]--;
        }

        else
            i++;
    }


}

void R_CSort(int arr[],int size,int place){  //place = 1,10,100(to get the ones,tenth,hundredth digit)
    int output[size];                    // to place the new level of sort
    int max,i,j;        //no need of max
    int C[10];         //as it stores count of 10 digits from 0 to  9
    
    for(i = 0;i<10;i++)
        C[i] = 0;
    
    for(i = 0; i < size; i++){
        C[(arr[i] / place) % 10]++; //increses count according to the current digit
    }

    for(i = 1;i<10;i++) // finds cumulative count --> helps in finding sorted position of element
        C[i] += C[i-1];

    i = 0,j = 0;

    for (i = size-1; i >= 0; i--){  //start from end and place elements one place before its count(index = count - 1) in the output array
        output[C[(arr[i] / place) % 10] - 1] = arr[i];
        C[(arr[i] / place) % 10]--;  
    }

    for (i = 0;i < size ; i++){ //copies output to originaa array
        arr[i] = output[i];
    }
}

void RadixSort(int arr[],int size){

    int max = GetMax(arr,size);
    int digits = 1;

    while(max != 0){ //to find no of digits of max element = no of loops
        max = max / 10;
        digits++;
    }

    for (int place = 1; digits > 0; place *= 10){
        R_CSort(arr,size,place);
        digits--;
    }
}

void Merge(int A[], int low,int mid,int high){

    int i = low,j = mid + 1,k = low;
    int B[100];
    
    while(i <= mid && j <= high){
        if (A[i] < A[j])
            B[k++] = A[i++];
        
        else
            B[k++] = A[j++];
    }

    for (;i <= mid;i++){
        B[k++] = A[i];
    }

    for (;j <= high; j++){
        B[k++] = A[j];
    }

    for (i = low;i <= high;i++){
        A[i] = B[i];
    }

}

void MergeSort(int A[],int low,int high){
    if (low < high){

        int mid = (low + high) / 2;
        MergeSort(A,low,mid);
        MergeSort(A,mid + 1,high);
        Merge(A,low,mid,high);

    }
}

void Delete(int A[],int n){

    int x,i,j,temp;
    x = A[n];
    A[1] = A[n];
    i = 1;
    j = i * 2;

    while( j < n -1){
        if (A[j] <  A[j + 1])
            j = j + 1;
        
        if (A[i] < A[j]){
            A[i] = temp;
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j = i * 2;

        }

        else
            break;
    }
    A[n] = x;





}

void HeapSort(int A[], int n){

    for (int i = n; i > 1; i--)
        Delete(A,n);

}



    
    

    




int main(){

    int arr[] = {-200,121,50,63,311,42,21,0,10};
    int size = 8;
    int comp = 0;
    HeapSort(arr,size);
    
    for (int i = 0; i < size; i++)
        printf("%d ",arr[i]);
}