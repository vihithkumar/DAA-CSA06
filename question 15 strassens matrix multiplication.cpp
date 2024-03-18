#include <stdio.h>
void strassenMultiply(int a[2][2], int b[2][2], int c[2][2]) {
    int m1, m2, m3, m4, m5, m6, m7;

    m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
    m2 = (a[1][0] + a[1][1]) * b[0][0];
    m3 = a[0][0] * (b[0][1] - b[1][1]);
    m4 = a[1][1] * (b[1][0] - b[0][0]);
    m5 = (a[0][0] + a[0][1]) * b[1][1];
    m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
    m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

    c[0][0] = m1 + m4 - m5 + m7;
    c[0][1] = m3 + m5;
    c[1][0] = m2 + m4;
    c[1][1] = m1 - m2 + m3 + m6;
}

int main() {
    int a[2][2], b[2][2], c[2][2];
    int i, j;
    printf("Enter the 4 elements of the first matrix: ");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter the 4 elements of the second matrix: ");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    strassenMultiply(a, b, c);

    printf("\nResultant matrix after Strassen's multiplication:\n");
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }

    return 0;
}
