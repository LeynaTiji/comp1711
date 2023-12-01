#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buffer_size = 100;

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

FitnessData arrayofdata[200];

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

FILE *open_file(char filename[], char mode[]){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        printf("Error: could not find or open the file.\n");
        exit(1);
    }
    return file;
    }


void bubblesort(int numofrecords){
    FitnessData temp;

    for (int j =0; j < numofrecords; j++){
        for (int k =0; k < numofrecords - j ; k++){
            if (arrayofdata[k].steps < arrayofdata[k+1].steps){
                temp = arrayofdata[k];
                arrayofdata[k] = arrayofdata[k + 1];
                arrayofdata[k + 1] = temp;

            }
        }
    }
}

int main() {
    
    char line[buffer_size];
    char filename[buffer_size];
    char line_buffer[buffer_size];
    
    int num_records = 0;

    printf("Enter Filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    FILE *file = open_file(filename, "r");

    while (fgets(line_buffer, buffer_size, file) != NULL) {
                // splits string and puts each value into an array
                tokeniseRecord(line_buffer, ',', arrayofdata[num_records].date, arrayofdata[num_records].time, &arrayofdata[num_records].steps);                
                num_records ++ ;
    }

    fclose(file);

    for (int i = 0; i < num_records; i++){
        if (arrayofdata[i].steps == 0){
            printf("Error: file is formatted incorrectly.\n");
            return 1;
        }
    }

    bubblesort(num_records);

    fopen (strcat(filename, ".tsv"), "w");

    for (int i = 0; i < num_records; i++) {
        fprintf(file, "%s\t%s\t%d\n", arrayofdata[i].date, arrayofdata[i].time, arrayofdata[i].steps);
    }

    fclose(file);

    printf("Data sorted and written to %s\n", filename);

    return 0;

}
