#include <stdio.h>

int binomialCoefficient(int n, int k) {
    int dp[n + 1][k + 1];
int i,j;
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    }

    return dp[n][k];
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = binomialCoefficient(n, k);
    printf("The binomial coefficient C(%d, %d) is: %d\n", n, k, result);

    return 0;
}
