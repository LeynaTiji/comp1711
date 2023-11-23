#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array
FITNESS_DATA arrayofdata[100];

FILE *open_file(char filename[], char mode[]){
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        printf("Error: could not open file\n");
        exit(1);
    } else {
        printf("File successfully loaded\n");
    }
    return file;
    }

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps){
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



// Complete the main function
int main() {

    char line[buffer_size];
    char filename[buffer_size];
    char line_buffer[buffer_size];

    int num_records = 0;
    char tempSteps[10];

    char choice;

    float mean;
    int rounded;
    int minVal = 50000;
    int maxVal = 0;
    int i;
    int j;
    int counter = 0;
    char * stepsarray[4]; 
    int longesttime = 0;

    while(1){

        printf("\n");
        printf("A: Specify the filename to be imported\n");                     
        printf("B: Display the total number of records in the file\n");                    
        printf("C: Find the data and time of the timeslot with the fewest steps\n");                     
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");                    
        printf("E: Find the mean step count of all the records in the file\n");       
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");                 
        printf("Q: Quit\n");

        choice = getchar();

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        case 'a':

            // get filename from the user
            printf("Input filename:");

            // these lines read in a line from the stdin (where the user types)
            // and then takes the actual string out of it
            // this removes any spaces or newlines.
            fgets(line, buffer_size, stdin);
            sscanf(line, " %s ", filename);

            FILE *file = open_file(filename, "r");
            while (fgets(line_buffer, buffer_size, file) != NULL) {
                // splits string and puts each value into an array
                tokeniseRecord(line_buffer, ",", arrayofdata[num_records].date, arrayofdata[num_records].time, tempSteps);
                //converts character to an integer
                arrayofdata[num_records].steps = atoi(tempSteps);
                num_records ++ ;
            }

            fclose(file);
            break;

        case 'B':
        case 'b':
            printf("Total records: %d\n", num_records);
            break;

        case 'C':
        case 'c':

            for(int i = 0 ; i < num_records; i++){
                if (minVal > arrayofdata[i].steps){
                    minVal = arrayofdata[i].steps;
                }
            }

            for(int j = 0 ; j < num_records; j++){
                if (minVal == arrayofdata[j].steps){
                    printf("Fewest steps: %s/%s\n", arrayofdata[j].date, arrayofdata[j].time);
                }
            }
            break;

        case 'D':
        case 'd':

            for(int i = 0 ; i < num_records; i++){
                if (maxVal < arrayofdata[i].steps){
                    maxVal = arrayofdata[i].steps;
                }
            }

            for(int j = 0 ; j < num_records; j++){
                if (maxVal == arrayofdata[j].steps){
                    printf("Largest steps: %s/%s\n", arrayofdata[j].date, arrayofdata[j].time);
                }
            }
            break;

        case 'E':
        case 'e':
        
            for (int j = 0; j < num_records; j++)
            {
                mean += arrayofdata[j].steps;
            }

            mean = mean / num_records;
            rounded = mean + 0.5;
            printf("Mean step count: %d\n", rounded);
            break;

        case 'F':
        case 'f':
            i = 0;
            for (i; i < num_records; i++){
                if (arrayofdata[i].steps > 500){
                    j = i;
                    while (arrayofdata[j].steps > 500){
                        counter ++;
                        j ++;
                    }

                    j --;

                    if (counter > longesttime){
                        longesttime = counter;

                        stepsarray[0] = arrayofdata[i].date;
                        stepsarray[1] = arrayofdata[i].time;
                        stepsarray[2] = arrayofdata[j].date;
                        stepsarray[3] = arrayofdata[j].time;
                    }

                    counter = 0;
                    i = j + 1;
                }
            }

            printf("Longest period start: %s %s\n", stepsarray[0], stepsarray[1]);
            printf("Longest period end: %s %s\n", stepsarray[2], stepsarray[3]);
            break;

        case 'Q':
        case 'q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice, Try again\n");

            break;
        }
     }
}