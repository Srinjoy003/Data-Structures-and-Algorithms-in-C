#include<stdio.h>
#include<string.h>
#include<limits.h>


#define I INT_MAX

void printPath(int parent[], int j, int vertex)
{
    
    if (parent[j] == -1){
        printf("%d => ",j);
        return;
    }

    printPath(parent, parent[j], vertex);

    if (j == vertex)
        printf("%d ", j);
    else    
        printf("%d => ", j);

}

int DFS(int A[][100], int u, int t, int n,int parent[],int visited[]){
    if (visited[u] == 0){
    
        visited[u] = 1;
    
        for (int v = 0; v < n;v++){
            if (A[u][v] != 0 && A[u][v] != I  && visited[v] == 0){
                parent[v] = u;
                DFS(A, v, t, n, parent,visited);
            }
        }
       
    }

    if (visited[t] == 1){
        return 1;
    }
    else    
        return 0;

    
}

int FFK(int cost[][100], int s, int t, int n){

    int i, j, u, v;
    int rGraph[100][100];

    for (i = 0; i < n; i++){ \
        for (j = 0; j < n; j++)
            rGraph[i][j] = cost[i][j];
    }

   

    

    int parent[n];
    int visited[n];
    int MaxFlow = 0;
    

    for (i = 0; i < n; i++){
        parent[i] = -1;
        visited[i] = 0;
    }
    j = 0;
    int path_flow;


    while (DFS(rGraph, s, t, n, parent,visited)) {



        
        path_flow = I;

        v = t;
        while (v != s){

            u = parent[v];
            path_flow = path_flow > rGraph[u][v] ? rGraph[u][v] : path_flow; 
            v = parent[v];

        }

        v = t;
        while (v != s){
            
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] = rGraph[v][u] == I ? path_flow : rGraph[v][u] + path_flow; 
            v = parent[v];
        }

        printPath(parent,t,s);
        printf("  Flow = %d\n",path_flow);

        

        MaxFlow += path_flow;

        

        for (i = 0; i < n; i++){
            parent[i] = -1;
            visited[i] = 0;
        }
    }
 
 
    return MaxFlow;

}



int main(){

    int cost[][100] =  {{0, 20, 10, I}, 
                        {I, 0, 30, 10}, 
                        {I, I, 0, 20}, 
                        {I, I, I, 0}};
    
  

    printf("\n\n");
    int m = FFK(cost, 0, 3, 4);
    printf("\nMax Flow : %d \n\n",m);

   
        

   

    



}