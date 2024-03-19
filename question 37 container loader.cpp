#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 10

bool allItemsPlaced(bool placed[], int n) {
    int i,k;
	for ( i = 0; i < n; i++) {
        if (!placed[i]) {
            return false;
        }
    }
    return true;
}

void arrangeItems(int containerLength, int weights[], bool placed[], int n, int currentLength, int currentIndex) {
    if (currentLength > containerLength) {
        return;
    }

    if (currentIndex == n && allItemsPlaced(placed, n)) {
        printf("Feasible arrangement: ");
       int i;
	    for ( i = 0; i < n; i++) {
            printf("%d ", placed[i] ? weights[i] : 0);
        }
        printf("\n");
        return;
    }

    placed[currentIndex] = true;
    arrangeItems(containerLength, weights, placed, n, currentLength + weights[currentIndex], currentIndex + 1);

    placed[currentIndex] = false;
    arrangeItems(containerLength, weights, placed, n, currentLength, currentIndex + 1);
}

int main() {
    int containerLength, n;

    printf("Enter the container length: ");
    scanf("%d", &containerLength);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[MAX_ITEMS];
   int i; printf("Enter the weights of the items:\n");
    for ( i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    bool placed[MAX_ITEMS] = {false};

    arrangeItems(containerLength, weights, placed, n, 0, 0);

    return 0;
}
