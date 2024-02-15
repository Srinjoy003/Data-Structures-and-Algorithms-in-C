#include<stdio.h>
#include<stdlib.h>

void par(int s[][10],int i,int j){

    if (i == j)
        printf("A%d ",i);
    
    else{
        printf("(");
        par(s,i,s[i][j]);
        par(s,s[i][j]+1,j);
        printf(")");
    }
}

void MMC(int n){

    int x,y;
    int a[n];

    for(int i = 1;i < n;i++){
        printf("Enter dimensions of matrix %d: ",i);
        scanf("%d %d",&x,&y);

        if (i == 1){
            a[i-1] = x;
            a[i] = y;
        }

        else if (x == a[i-1])
            a[i] = y;
        
        else{
            printf("\nInvalid Dimensions");
            return;
        }

    }

    
    int m[n][n];
    int s[n][10];

    for (int row = 0;row < n;row++){
        for (int col = 0;col < n;col++){
            m[row][col] = 0;
            s[row][col] = 0;
        }

    }
    int j,min,q;

    for (int d = 1;d < n-1;d++){ // d is the diff btw i and j .used to do diagonal traversal of s and m

        for(int i = 1 ;i < n-d; i++){
            j = i + d;
            min = INT_MAX;

            for (int k = i;k <= j-1;k++){

                q = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];

                if (q < min){
                    min = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = min;


        }
    }
    
    printf("\nMin Cost = %d\n\n",m[1][n-1]);
    printf("array for min cost\n\n");
    for (int row = 1;row < n;row++){
        for (int col = 1;col < n;col++){
            printf("%d\t",m[row][col]);
        }
        printf("\n");

    }
    printf("\n\n");
    printf("array for parenthesization\n\n");


    for (int row = 1;row < n;row++){
        for (int col = 1;col < n;col++){
            printf("%d\t",s[row][col]);
        }
        printf("\n");

    }
    printf("\n\n");

    par(s,1,n-1);
    printf("\n\n");

}


int main(){
    int n,x,y;
    printf("\n\nEnter no of matrices: ");
    scanf("%d",&x);
    n = x+1;
   

    MMC(n);


    

    return 0;
}