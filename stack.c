#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int Push(int arr[],int *top,int size,int data){

    if (*top == size - 1){
        printf("Oveflow\n");
    }
    else{
        (*top)++;
        arr[*top] = data;
        
    }
    

}


int Pop(int arr[],int *top,int size){

    if (*top < 0){
        printf("Underflow\n");
    }
    else{
        //printf("Popped %d\n",arr[top]);
        (*top)--;

        
    }

}

void Display(int arr[],int top){
    for (int i = 0;i <= top ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

/*Using Linked LIst
    push = insert at begin
    pop = delete at begin
    display = print 
*/

int main(){
    int top = -1;
    int arr[30];
    int size = 30;
   

    int input = 5,data;
    while(input != 0){
        printf("\n1-Push  2-Pop  3-Display 0-Exit\n\n");
        printf("Enter your choice");
        scanf("%d",&input);
        
        if (input == 0){
            break;
        }
        else if (input == 1){
            printf("Enter the value");
            scanf("%d",&data);
            printf("\n");
            Push(arr ,&top,size,data);
        }
        else if(input == 2){
            Pop(arr,&top,size);
        }
        
        else if(input = 3){
            Display(arr,top);
        
        }
        
        else
            printf("\nInvalid Input");

        
    }

   /* char str[30];
    printf("Enter the expression");
    gets(str);
    int i = 0;
    printf("%s\n",str);

   

    while(str[i] != '\0'){
        
    // Scan all characters one by one
    
        // If the scanned character is an operand (number here),
        // push it to the stack.
        if (isdigit(str[i])){
            top = Push(arr,top,size,str[i] - '0');
        
        }
        // If the scanned character is an operator, pop two
        // elements from stack apply the operator
        else{
            int val1 = arr[top];
            top = Pop(arr,top,size);
            int val2 = arr[top];
            top = Pop(arr,top,size);
            
            if (str[i] == '+')
                top = Push(arr,top,size,val2 + val1);
            
            else if (str[i] == '-')
                top = Push(arr,top,size,val2 - val1);
            
            else if (str[i] == '*')
                top = Push(arr,top,size,val2 * val1);
            
            else if (str[i] == '/')
                top = Push(arr,top,size,val2 / val1);

            else if (str[i] == '^')
                top = Push(arr,top,size,pow(val2,val1));
           


            
        }
        Display(arr,top);
        i++;
    
        
    }
 
    printf("\n%d",arr[top]);*/
    return 0;
}
//2536+**5/2-