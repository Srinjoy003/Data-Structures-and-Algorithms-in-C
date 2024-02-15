#include<stdio.h>


int main(){

    // INPUT BLOCK--------------------------------------------------------------------------------------

    int n = 2,m = 2;

    printf("\nEnter the number of terms in 1st polynomial: ");
    scanf("%d",&n);

    printf("\nEnter the number of terms in 2nd polynomial: ");
    scanf("%d",&m);


    int arr1[4][m+n];
    int i = 0;
    
    printf("\n\nPOLYNOMIAL 1");
    printf("\nEnter coeff ,power of x,power of y,power of z of terms:\n");


    for (int i = 0; i < n ;i++){
        printf("\nterm %d:",i+1);
        scanf("%d %d %d %d",&arr1[0][i],&arr1[1][i],&arr1[2][i],&arr1[3][i]);

    }

    printf("\nPOLYNOMIAL 2");
    printf("\nEnter coeff ,power of x,power of y,power of z of terms\n\n:");


    for (int j = n; j < m + n ;j++){
        printf("\nterm %d:",j+1-n);
        scanf("%d %d %d %d",&arr1[0][j],&arr1[1][j],&arr1[2][j],&arr1[3][j]);

    }
    
    //DISPLAY POLYNOMIAL BLOCK--------------------------------------------------------------------------


    printf("\n\nPolynomial 1 :  ");

    for (int i = 0; i < n - 1 ;i++){
        printf("%dx^%d y^%d z^%d  +  ",arr1[0][i],arr1[1][i],arr1[2][i],arr1[3][i]);
    }
    printf("%dx^%d y^%d z^%d    ",arr1[0][n-1],arr1[1][n-1],arr1[2][n-1],arr1[3][n-1]);

    printf("\n\nPolynomial 2 :  ");

    for (int j = n ; j < m + n -1 ;j++){
        printf("%dx^%d y^%d z^%d  +  ",arr1[0][j],arr1[1][j],arr1[2][j],arr1[3][j]);
    }
    printf("%dx^%d y^%d z^%d    ",arr1[0][m+n-1],arr1[1][m+n-1],arr1[2][m+n-1],arr1[3][m+n-1]);
    
 
    // ADDITION BLOCK---------------------------------------------------------------------------------------
    int col = m+n;
    
    
    int count = 0;
    for(int i = 0;i < n;i++){
        for (int j =  n ; j < m + n; j++){
            if (arr1[1][i] == arr1[1][j] && arr1[2][i] == arr1[2][j] && arr1[3][i] == arr1[3][j]){
                arr1[0][i] += arr1[0][j];
                arr1[0][j] = 0;
                
                
                
            }
        }
    }
    
  
    //REMOVING USELESS TERMS--------------------------------------------------------------------
    
    for(int i = 0;i < col;i++){
        if (arr1[0][i] == 0){
            for (int x = i; x < col-1; x++){
                arr1[0][x] = arr1[0][x+1];
                arr1[1][x] = arr1[1][x+1];
                arr1[2][x] = arr1[2][x+1];
                arr1[3][x] = arr1[3][x+1];
                count += 1;
            }
                  
                
            
            i--;
            col--;
            
        }
    }
    
    //FINAL OUTPUT BLOCK-------------------------------------------------------------------------
    
    printf("\n\nSum of Polynomials: ");
    for (int i = 0;i < col-1;i++ ){
        printf("%dx^%d y^%d z^%d + ",arr1[0][i],arr1[1][i],arr1[2][i],arr1[3][i]);
    }
    printf("%dx^%d y^%d z^%d ",arr1[0][col-1],arr1[1][col-1],arr1[2][col-1],arr1[3][col-1]);
    return 0;

}
    
