#include "utilities.h"
#include <ctype.h> //allows for upper function

int main()
{
    // array of daily readings
    reading daily_readings[100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char ogChoice, choice;
    int counter = 0;
    float mean = 0;

    while (1)
    {
        // FILE *input = open_file(filename, "r");

        // int read_file(FILE *input, reading *daily_readings, int counter);

        FILE *file = fopen(filename, "r");
        if (file == NULL){
            printf("Error: File could not be opened\n");
        exit(1);
        }

        char line_buffer[buffer_size];
    
        while (fgets(line_buffer, buffer_size, file) != NULL) {
            tokeniseRecord(line_buffer, ",", daily_readings[counter].date, & daily_readings[counter].bloodIron);
            counter ++;
        }
        
        fclose(file);

        printf("\n");
        printf("A: View all your blood iron levels\n");                       // BRONZE
        printf("B: View your average blood iron level\n");                    // BRONZE
        printf("C: View your lowest blood iron level\n");                     // SILVER
        printf("D: View your highest blood iron level\n");                    // SILVER
        printf("E: View the blood iron levels for a specific month\n");       // SILVER/GOLD
        printf("F: See some additional statistics about your iron levels\n"); // GOLD - see readme.md
        printf("G: Generate a graph of your iron levels\n");                  // GOLD/PLATINUM - see readme.md
        printf("Q: Exit the program\n");

        // get the next character typed in and store in the 'choice'
        choice = getchar();
        // choice = toupper(ogChoice);

        // this gets rid of the newline character which the user will enter
        // as otherwise this will stay in the stdin and be read next time
        while (getchar() != '\n');

        // switch statement to control the menu.
        switch (choice)
        {
        // this allows for either capital or lower case
        case 'A':
        
            for (int i = 0; i < counter; i++)
            {
                printf("%s - Blood iron: %.1f\n", daily_readings[i].date, daily_readings[i].bloodIron);
            }
            break;

        case 'B':
            counter = 0;

            for (int j = 0; j < counter; j++)
            {
                mean += daily_readings[j].bloodIron;
            }
            mean /= counter;
            printf("Your average blood iron was %.2f\n", mean);
            break;

        case 'C':
            return 0;
            break;

        case 'D':
            return 0;
            break;

        case 'E':
            return 0;
            break;

        case 'F':
            return 0;
            break;

        case 'G':
            return 0;
            break;

        case 'Q':
            return 0;
            break;

        // if they type anything else:
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}