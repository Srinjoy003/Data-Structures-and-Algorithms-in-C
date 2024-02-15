#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void KMP(char string[], char pattern[]){

    int i,len,j;
    int n = strlen(string);
    int m = strlen(pattern);
    int lps[m];
    

    len = 0;
    i = 2;
    lps[1] = 0;

    while(i < m){

        if( pattern[len+1] == pattern[i]){
            len++;
            lps[i] = len;
            i++;
        }

        else if( len != 0)
            len = lps[len];

        else{

            lps[i] = 0;
            i++;
        }
    }

    
    printf("\n\n");

    i = 1;
    j = 0;
   


    while (n -i >= m - j - 1 ){ 


        if (pattern[j+1] == string[i]){
            //printf("%d %d %c %c\n",i,j,string[i],pattern[j+1]);

            i++;
            j++;
        }



        if (j == m - 1){
            printf("Found Pattern at index %d \n",i -j);
        
            j = lps[j];
        }

        else if (i < n +1 && pattern[j+1] != string[i]){
            //printf("%d %d %c %c\n",i,j,string[i],pattern[j+1]);

            
            if (j != 0 && j != lps[j])
                j = lps[j];
            else
                i++;
        }
    }

    
}





int main(){

    /*char string[] = "@bacbababacababaca";
    //char pattern[] = "ababababababa";
    char pattern[] = "@ababaca";

    

    char string[] = "@AABAACAADAABAABA";
    char pattern[] = "@AABA";*/

    /*char string[] = "@ababcabcabababd";
    char pattern[] = "@ababd";*/

    char string[100];
    char pattern[100];

    printf("\n\nEnter String: ");
    scanf("%s",string + 1);

    printf("Enter Pattern: ");
    scanf("%s",pattern + 1);
    printf("\n\n");



    KMP(string, pattern);
    printf("\n\n");

}