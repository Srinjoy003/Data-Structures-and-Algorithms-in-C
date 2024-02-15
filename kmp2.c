#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void KMP(char string[], char pattern[]){

    int i,len,j;
    int n = strlen(string);
    int m = strlen(pattern);
    int lps[m];


    len = 0;
    i = 1;
    lps[0] = 0;

    while(i < m){

        if( pattern[len] == pattern[i]){
            len++;
            lps[i] = len;
            i++;
        }

        else if( len != 0)
            len = lps[len-1];

        else{

            lps[i] = 0;
            i++;
        }
    }

    for(i = 0;i < m;i++)
        printf("%d ",lps[i]);
    printf("\n");

    i = 0;
    j = 0;

    while ((n -i) >= (m - j)){ // more characters in pattern are left than in string(as i can't go back)

        if (pattern[j] == string[i]){
            i++;
            j++;
        }

        if (j == m - 1){
            printf("Found Pattern at index %d \n",i -j);
            j = lps[j-1];
        }

        else if (i < n && pattern[j] != string[i]){
            
            if (j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main(){

    /*char string[] = "bacbababacababaca";

    char pattern[] = "ababaca";*/

    

    /*char string[] = "AABAACAADAABAABA";
    char pattern[] = "AABA";*/

    char string[100];
    char pattern[100];

    printf("Enter String: ");
    scanf("%s",string );

    printf("Enter Pattern: ");
    scanf("%s",pattern );


   
   

    KMP(string, pattern);
}