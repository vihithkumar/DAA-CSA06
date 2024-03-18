#include <stdio.h>

void copyString(char source[], char destination[], int index) {
    if (source[index] == '\0') {
        destination[index] = '\0';
        return;
    }
    destination[index] = source[index];
    copyString(source, destination, index + 1);
}

int main() {
    char source[50], destination[50];

    printf("Enter a string: ");
    scanf("%s", source);

    copyString(source, destination, 0);

    printf("Source string: %s\n", source);
    printf("Copied string: %s\n", destination);

    return 0;
}
