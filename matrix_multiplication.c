#include<stdio.h>
#include<stdlib.h>

int main(){

    int r1, c1, r2, c2, sum, i, j, k;
    
    printf("Enter the no of rows and columns of 1st array");
    scanf("%d %d",&r1,&c1);

    printf("Enter the no of rows and columns of 2nd array");
    scanf("%d %d",&r2,&c2);

    if (c1 != r2)
        printf("Matrix cannot be muliplied");

    else{


        int **arr1 = (int**) malloc (r1 * sizeof(int*));
        int **arr2 = (int**) malloc (r2 * sizeof(int*));
        int **arr3 = (int**) malloc (r1 * sizeof(int*));

        for (i = 0; i < r1; i++){
            arr1[i] = (int*) malloc (c1 * sizeof(int));
        }
        for (i = 0; i < r2; i++){
            arr2[i] = (int*) malloc (c2 * sizeof(int));
        }
        for (i = 0; i < r1; i++){
            arr3[i] = (int*) malloc (c2 * sizeof(int));
        }


        FILE *fp;
        FILE *fr;
        fp = fopen("data.txt","w+");
        fr = fopen("res.txt","w+");

        for (i = 0; i < r1; i++){
            for (j = 0; j < c1; j++){
                fprintf(fp,"%d ",rand() % 10);
            }
            fprintf(fp,"\n");
        }

        fprintf(fp,"\n");

        for (i = 0; i < r2; i++){
            for (j = 0; j < c2; j++){
                fprintf(fp,"%d ",rand() % 10);
            }
            fprintf(fp,"\n");
        }

        fclose(fp);
        fp = fopen("data.txt","r");

        for (i = 0; i < r1; i++){
            for (j = 0; j < c1; j++){
                fscanf(fp,"%d",&arr1[i][j]);
            }
        }

        for (i = 0; i < r2; i++){
            for (j = 0; j < c2; j++){
                fscanf(fp,"%d",&arr2[i][j]);
            }
        }

        for (i = 0; i < r1; i++){
            sum = 0;
            for (j = 0; j < c2; j++){
                for (k = 0; k < c1; k++){
                    sum += arr1[i][k] * arr2[k][i];
                }
                arr3[i][j] = sum;
            }

        }

        for (i = 0; i < r1; i++){
            for (j = 0; j < c2; j++){
                fprintf(fr,"%d ",arr3[i][j]);
            }
            fprintf(fr,"\n");
        }

        fclose(fp);
        fclose(fr);
    }

    return 0;
}