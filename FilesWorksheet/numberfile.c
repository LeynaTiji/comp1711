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
    char filename [] = "numbers.dat";
    // call file function
    FILE *file = open_file(filename, "a+");

    int buffer_size = 100;
    float total = 0, average;
    int count = 0;
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        total = total + atof(line_buffer);
        count++ ;
    }

    average = total / count;
    
    fprintf(file, "%f\n", average);

    fclose(file);
    return 0;
}