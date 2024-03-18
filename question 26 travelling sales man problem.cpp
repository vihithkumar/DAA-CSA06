#include <stdio.h>
#include <limits.h>

#define MAX_N 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int n, int graph[MAX_N][MAX_N], int mask, int pos, int dp[MAX_N][1 << MAX_N]) {
    if (mask == (1 << n) - 1) {
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int minCost = INT_MAX,i;

    for (i = 0; i < n; i++) {
        if ((mask & (1 << i)) == 0) {
            int newMask = mask | (1 << i);
            int cost = graph[pos][i] + tsp(n, graph, newMask, i, dp);
            minCost = min(minCost, cost);
        }
    }

    dp[pos][mask] = minCost;

    return minCost;
}

int main() {
    int n;
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    int graph[MAX_N][MAX_N];

    printf("Enter the cost matrix:\n");
    int i,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int dp[MAX_N][1 << MAX_N];
    for ( i = 0; i < MAX_N; i++) {
        for ( j = 0; j < (1 << MAX_N); j++) {
            dp[i][j] = -1;
        }
    }

    int result = tsp(n, graph, 1, 0, dp); 
    printf("The minimum cost of the TSP is: %d\n", result);

    return 0;
}
