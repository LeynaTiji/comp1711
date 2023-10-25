#include <stdio.h>

int main() {
    char filename [] = "squares.dat";
    FILE *file = fopen(filename, "w"); // or "a", "w+", "a+"
    if (file == NULL) {
        perror("");
        return 1;
    }

    int number, square;

    printf("Type a number: ");
    scanf("%d", &number);

    for (int i = 0; i < number; i++){

        square = i * i;
        fprintf(file, "%d\n", square);
    }

    fclose(file);
    return 0;
}