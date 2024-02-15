#include <stdio.h>

void TowerofHanoi(int n, char from, char using, char to,int *comp){
    if (n > 0){
        (*comp)++;
        TowerofHanoi( n-1, from, to,  using,comp);
        printf("Move Disk from %c to %c\n",from,to);
        TowerofHanoi( n-1, using, from,  to,comp);
    }
}
float pow_n(float x,int n,int *comp){

    (*comp)++;
    if (n == 0)
        return 1;

    else if (n == 1)
        return x;
    
    else if (n > 0)
        return x * pow_n(x,n-1,comp);

    else if (n < 0)
        return pow_n(x,n+1,comp) / x;
}

float power(float x,int n,int *comp){
    
   
    if (n == 0)
        return 1;
    
    else if (n == 1)
        return x;

   

    else if (n % 2 == 0){
         (*comp)++;
        return power(x*x,n/2,comp);
    }
    else if(n % 2 != 0){
        (*comp)++;

        if (n > 0)
            return x * power(x*x,n/2,comp);
        else
            return power(x*x,n/2,comp) / x;
    }
}

float TaylorSeries(float x,int n,int a){ //1 + x/1! + x^2/2! + x^3/3!..... = (1 + x(1 + x/2(1 + x/3(......))))

    if (a == 1)
        return  1 + TaylorSeries(x,n,a+1);
    
    if (a == n )
        return x/(a-1);
    
    else

        return (x/(a-1))*(1 + TaylorSeries(x,n,a+1));
    

}



int main(){
    
    int comp1 = 0,comp2 = 0,comp3 = 0,comp4 = 0;
    float a = pow_n(2,8,&comp1);
    float b = power(2,8,&comp2);
    float c = pow_n(2,-10,&comp3);
    float d = power(2,-10,&comp4);

    printf("\n\n           O(n)         O(log n)\n\n");
    printf("2 ^ 8\n\n");
    printf("Result      %f    %f\n",a,b);
    printf("Comparisons %d             %d\n\n",comp1,comp2);
    printf("2 ^ -10\n\n");
    printf("Result      %f    %f\n",c,d);
    printf("Comparisons %d             %d\n\n",comp3,comp4);
    
    
}