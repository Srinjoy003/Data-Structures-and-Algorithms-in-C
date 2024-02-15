#include<stdio.h>
#include<string.h>


int Push(char arr[],int *top,int size,int data){

    if (*top == size - 1){
        printf("Oveflow\n");
    }
    else{
        (*top)++;
        arr[*top] = data;
        
    }

}


char Pop(char arr[],int *top,int size){

    if (*top < 0){
    }
    else{
        
        char x = arr[*top];
        (*top)--;
        return x;


        
    }

}

void Display(char arr[],int top){
    for (int i = 0;i <= top ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int Precedence(char s)
{
    if (s == '+' || s == '-') 
        return 1;
    
    if (s == '*' || s == '/') 
        return 2;
    
    if (s == '^') 
        return 3;

    return -1;
}

int InfixToPostfix(char exp[])
{
    int i, k = -1;
    char x;
    char stack[30];
    char postfix[30];
    int top = -1, size = 30;
    
 
    
 
    for (i = 0; exp[i] != '\0'; i++) {
 
        
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
            k++;
            postfix[k] = exp[i];
        }
            
 
       
        else if (exp[i] == '(')
            Push(stack, &top, size, exp[i]);
 
        
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '('){
                k++;
                postfix[k] = Pop(stack, &top, size);
            }
            if (top != -1 && stack[top] != '(')
                return -1; 
            else
                x = Pop(stack, &top, size);
        }
 
        else 
        {
            while (top != -1 && Precedence(exp[i]) <= Precedence(stack[top])){
                k++;
                postfix[k] = Pop(stack, &top, size);
            }
            Push(stack, &top, size, exp[i]);
        }
    }
 
    
    while (top != -1){
        k++;
        postfix[k] = Pop(stack, &top, size);;
    }
    k++;
    postfix[k] = '\0';
    printf("%s", postfix);
}

int main(){
    char exp[30];
    printf("Enter Infix Expression : ");
    scanf("%s",&exp);
    //char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    printf("\nPostfix Expression : ");
    InfixToPostfix(exp);
    return 0;
}