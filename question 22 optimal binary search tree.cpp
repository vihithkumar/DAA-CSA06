#include <stdio.h>
#include <limits.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}
int optimalBST(int keys[], int freq[], int n) {
    int dp[n + 1][n + 1];
    int i,k,r;
	for (i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }
    int length;
    
	for (length = 2; length <= n; length++) {
        for ( i = 0; i <= n - length + 1; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX; 
            int sumFreq = 0;
            for ( k = i; k <= j; k++) {
                sumFreq += freq[k];
            }
            for (r = i; r <= j; r++) {
                int cost = ((r > i) ? dp[i][r - 1] : 0) + ((r < j) ? dp[r + 1][j] : 0) + sumFreq;
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);

    int keys[n], freq[n],i;

    for ( i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &keys[i]);

        printf("Enter frequency for key %d: ", i + 1);
        scanf("%d", &freq[i]);
    }
    int result = optimalBST(keys, freq, n);
    printf("The minimum expected search cost for the optimal binary search tree is: %d\n", result);

    return 0;
}
