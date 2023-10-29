#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Function to open a file and return it to the main function
    FILE *open_file(char filename[], char mode[]) {
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit(1);
    }
    return file;

    }


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

int main() {
    int num_records = 0;
    char tempSteps[10];
    FITNESS_DATA arrayofdata[200] ;
    char filename [] = "FitnessData_2023.csv";
    // call file function
    FILE *file = open_file(filename, "r");

    int buffer_size = 100;
    char line_buffer[buffer_size];

    while (fgets(line_buffer, buffer_size, file) != NULL) {
        // splits string and puts each value into an array
        tokeniseRecord(line_buffer, ",", arrayofdata[num_records].date, arrayofdata[num_records].time, tempSteps);
        // arrayofdata[num_records].steps = atoi(tempSteps);
        printf("%s", arrayofdata[num_records].date);
        num_records ++ ;
    }

    printf("Number of records in file: %d\n", num_records);

    fclose(file);
    return 0;
}
