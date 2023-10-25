#include <stdio.h>
#include <stdlib.h> //defines exit()

// create file function
FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit(1);
    }
    return file;
} 

int main() {
    char filename [] = "squares.dat";
    // call file function
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    float total = 0, average = 0, count = 0;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total = total + atoi(line_buffer);
        count++ ;
    }

    average = total / count;

    printf("%f", average);

    fclose(file);
    return 0;
}