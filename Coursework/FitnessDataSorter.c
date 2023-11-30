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
void tokeniseRecord(char *record, char *delimiter, char *date, char *time, int *steps) {
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


int main() {
    
    char line[buffer_size];
    char filename[buffer_size];
    char line_buffer[buffer_size];

    int num_records = 0;
    char tempSteps[10];

    printf("Enter Filename: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL){
        printf("Error: could not find or open the file.\n");
        exit(1);
    } else {
        return file;
        while (fgets(line_buffer, buffer_size, file) != NULL) {
                // splits string and puts each value into an array
                tokeniseRecord(line_buffer, ",", arrayofdata[num_records].date, arrayofdata[num_records].time, tempSteps);
                //converts character to an integer
                arrayofdata[num_records].steps = atoi(tempSteps);
                num_records ++ ;
        }
    }

    // for (int i =0; i < num_records; i++){
    //     if (arrayofdata[i].date == NULL){
    //         printf("Error: file is formatted incorrectly.\n");
    //     } else if (arrayofdata[i].time == NULL){
    //         printf("Error: file is formatted incorrectly.\n");
    //     } else if (arrayofdata[i].steps == NULL){
    //         printf("Error: file is formatted incorrectly.\n");
    //     }
    // }

}