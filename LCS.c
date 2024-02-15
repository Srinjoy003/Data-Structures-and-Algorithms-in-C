#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int LCS(char A[],char B[],int m,int n){

    int i,j;
    int L[m + 1][n + 1];

    for(i = 0 ; i <= m ; i++){
        for(j = 0 ; j <= n ; j++){

        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if(A[i-1] == B[j-1])
            L[i][j] = 1 + L[i-1][j-1];
        

        else
            L[i][j] = L[i-1][j] > L[i][j-1] ? L[i-1][j] : L[i][j-1];
        }
    }

    for(i = 0 ; i <= m ; i++){
        for(j = 0 ; j <= n ; j++){
            printf("%d\t",L[i][j]);
        }
        printf("\n");
    }

    int index = L[m][n];
    char lcs[index + 1];
    lcs[index] = '\0'; 
    
 
   
    i = m;
    j = n;
    while (i > 0 && j > 0) {
        
        if (A[i - 1] == B[j - 1]) {
            lcs[index - 1] = A[i - 1]; 
            i--;
            j--;
            index--; 
        }
 
        
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    printf("\n\n%s",lcs);
    
    
}



int main(){
    int i, j, m, n;

    char A[100];
    char B[100];

    printf("\n\nEnter 1st sequence : ");
    scanf("%s",A);
    printf("Enter 2nd sequence : ");
    scanf("%s",B);
    printf("\n");

    m = strlen(A);
    n = strlen(B);

    
    LCS(A,B,m,n);
    
    return 0;

}
