#include <stdio.h>
#include <stdbool.h>

#define N 10  
void printBoard(int board[N][N], int n) {
    int i,j;
	for ( i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", (board[i][j] == 1) ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}
bool isSafe(int board[N][N], int row, int col, int n) {
    int i,j;
	for ( i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}
bool solveNQueens(int board[N][N], int col, int n) {
    if (col >= n) {
        printBoard(board, n);
        return true;
    }

    bool result = false;
int i;
    for ( i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            result = solveNQueens(board, col + 1, n) || result;

            board[i][col] = 0;
        }
    }

    return result;
}

int main() {
    int n;

    printf("Enter the value of n for N-Queens problem: ");
    scanf("%d", &n);

    int board[N][N];
int i,j;
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }

    if (!solveNQueens(board, 0, n)) {
        printf("No solution exists for the given value of n.\n");
    }

    return 0;
}
