#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];

    int i,w;
	for ( i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];
int i;
    for (i = 0; i < n; i++) {
        printf("Enter weight for item %d: ", i + 1);
        scanf("%d", &weights[i]);

        printf("Enter value for item %d: ", i + 1);
        scanf("%d", &values[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(capacity, weights, values, n);
    printf("The maximum value that can be obtained is: %d\n", result);

    return 0;
}
