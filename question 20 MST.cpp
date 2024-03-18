#include <stdio.h>
#include <limits.h>
#define MAX_VERTICES 10
int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;
    int v;
    for ( v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Edge   Weight\n");
    int i;
    for (i = 1; i < vertices; i++) {
        printf("%d - %d    %d\n", parent[i], i, graph[i][parent[i]]);
    }
}
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES]; 
    int key[MAX_VERTICES];    
    int mstSet[MAX_VERTICES]; 
    int i,count=0;
    for ( i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1; 
    for ( count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = 1; 
        int v;
        for (v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, graph, vertices);
}

int main() {
    int vertices;

    printf("Enter the number of vertices (maximum %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the weighted adjacency matrix for the graph:\n");
    int i,j;
    for ( i = 0; i < vertices; i++) {
        for ( j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    primMST(graph, vertices);

    return 0;
}
