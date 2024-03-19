#include <stdio.h>

#define MAX_SIZE 10  
void printSubset(int subset[], int size) {
    printf("Subset: {");
    int i,j;
    for ( i = 0; i < size; i++) {
        printf("%d", subset[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("}\n");
}

void generateSubsets(int arr[], int subset[], int n, int sum, int currIndex, int targetSum) {
    if (sum == targetSum) {
        printSubset(subset, currIndex);
    }
int i;
    for (i = currIndex; i < n; i++) {
        subset[currIndex] = arr[i];
        generateSubsets(arr, subset, n, sum + arr[i], currIndex + 1, targetSum);
    }
}

int main() {
    int n, targetSum;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[MAX_SIZE];
    printf("Enter the array elements:\n");
    int i;
    for ( i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    int subset[MAX_SIZE];

    generateSubsets(arr, subset, n, 0, 0, targetSum);

    return 0;
}
