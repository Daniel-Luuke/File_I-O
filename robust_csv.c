#include <stdio.h>
#include <string.h>

int main(){
    FILE *file = fopen("students.csv", "r");

    if (file == NULL){
        fprintf(stderr, "Error: Could not find students.csv!\n");
        return 1;
    }

    char line[100]; // Buffer to hold one line of text (max 99 characters)
    printf("--- Processing Student Records ---\n");

    // 1. READ THE FILE LINE BY LINE
    // fgets reads up to 99 chars or until a newline, then stores it in 'line'.
    while (fgets(line, sizeof(line), file)){

        char name[20];
        char scoreStr1[10], scoreStr2[10], scoreStr3[10];
        int s1, s2, s3;

        // 2. PARSE THE CSV LINE
        // sscanf attempts to extract data using a specific format.
        // It returns the number of items successfully matched and assigned.
        // Here, we expect 4 items: string, string, string, string.
        int itemsRead = sscanf(line, "%[^,],%[^,],%[^,],%[^\n]",
                               name, scoreStr1, scoreStr2, scoreStr3);

        if (itemsRead != 4){
            printf("WARNING: Skipping malformed line format: %s", line);
            continue; // Skip to the next line in the while loop
        }

        // 3. EXCEPTION HANDLING (Simulated via Return Codes)
        // We manually convert the strings to integers using sscanf.
        // If the string is "Error", sscanf will fail to convert it
        // and will NOT return 1.
        int valid1 = sscanf(scoreStr1, "%d", &s1);
        int valid2 = sscanf(scoreStr2, "%d", &s2);
        int valid3 = sscanf(scoreStr3, "%d", &s3);

        if (valid1 == 1 && valid2 == 1 && valid3 == 1){
            // All three scores were valid numbers!
            double average = (s1 + s2 + s3) / 3.0;
            printf("%s -> Average: %.2f\n", name, average);
        }else{
            // One or more scores were corrupted
            printf("WARNING: Skipping malformed record for %s (Invalid score data).\n", name);
            // Because we handled the error, the loop continues to the next student!
        }
    }

    fclose(file);
    printf("\n--- Processing Complete ---\n");
    return 0;

}