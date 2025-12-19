#include <stdio.h>
#include <stdlib.h>
#define max 100

int visited[max];

void DFS(int a[max][max], int n, int v){
    visited[v] = 1;
    for(int i = 0; i < n; i++){
        if(a[v][i] == 1 && !visited[i]){
            DFS(a, n, i);
        }
    }
}

int main(){
    int n, i, j, a[max][max];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix: ");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(i = 0; i < n; i++){
        visited[i] = 0;
    }

    DFS(a, n, 0);

    for(i = 0; i < n; i++){
        if(!visited[i]){
            printf("Graph is NOT CONNECTED.");
            return 0;
        }
    }

    printf("Graph IS CONNECTED.");

    return 0;
}