#include <stdio.h>
#include <stdlib.h>
#define max 100

int q[max], front = -1, rear = -1, visited[max];

void EnQ(int v){
    if(rear == max-1) return;
    if(front == -1) front = 0;
    q[rear++] = v;
}

int DeQ(){
    if(front == -1 || front > rear) return -1;
    return q[front++];
}

void BFS(int a[max][max], int n, int start){
    int i, v;
    for(i = 0; i < n; i++){
        EnQ(start);
        visited[start] = 1;
        printf("BFS Traversal: ");
        while((v = DeQ()) != -1){
            printf("%d ", v);
            for(i = 0; i < n; i++){
                if(a[v][i] = 1 && !visited[i]){
                    EnQ(i);
                    visited[i] = 1;
                }
            }
        }
    }
}

int main(){
    int n, i, j, start, a[max][max], v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix: ");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter starting vertex: ");
    scanf("%d", &v);
    BFS(a, n, start);

    return 0;
}