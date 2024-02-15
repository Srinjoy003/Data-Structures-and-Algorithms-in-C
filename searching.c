

#include <stdio.h>

void bubbleSort(int array[], int size) {

  // loop to access each array element
  for (int step = 0; step < size - 1; ++step) {
      
    // loop to compare array elements
    for (int i = 0; i < size - step - 1; ++i) {
      
      // compare two adjacent elements
      // change > to < to sort in descending order
      if (array[i] > array[i + 1]) {
        
        // swapping occurs if elements
        // are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}


int binarySearch(int arr[], int size, int x)
{
    int high = size -1;
    int low = 0;
    while (low <= high) {
        int mid = low + ((high - low)*(x - arr[low])) /(arr[high] - arr[low]);
 
        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;
 
        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;
 
        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }
 
    // if we reach here, then element was
    // not present
    return -1;
}
 
int main(){
    int s[] = {3,4,6,2,0};
    int size = sizeof(s)/sizeof(s[0]);
    bubbleSort(s,size);
    for (int i = 0; i < size; i++){
        printf("%d ",s[i]);
    }
    int index = binarySearch(s,size,2);
    printf("\n%d",index);
    return 0;
}