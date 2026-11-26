#include <stdio.h>  // REQUIRED for FILE, fopen, fscanf, fprintf, fclose
#include <stdlib.h> // REQUIRED for exit()

int main(){
    // 1. DECLARE A FILE POINTER
    // FILE is a structure that holds info about the open file.
    FILE *inputFile;
    FILE *outputFile;

    // 2. OPEN FILE FOR READING ("r" mode)
    // fopen returns NULL if it fails to open the file.
    inputFile = fopen("numbers.txt", "r");

    // Check if the file was successfully opened
    if (inputFile == NULL){
        printf("Error: Could not open numbers.txt for reading!\n");
        return 1; // Exit with error code
    }

    int num;
    int sum = 0;

    printf("Reading numbers from file...\n");

    // 3. READ DATA IN A LOOP
    // fscanf works just like scanf, but takes the FILE pointer as the first argument.
    // It returns EOF (End Of File) when it reaches the end.
    while (fscanf(inputFile, "%d", &num) != EOF){
        printf("Read: %d\n", num);
        sum += num;
    }

    // 4. CLOSE THE FILE
    // Always close a file when you are done with it to save resources.
    fclose(inputFile);

    printf("Total Sum: %d\n", sum);

    // 5. OPEN FILE FOR WRITING ("w" mode)
    // If sum.txt doesn't exist, it creates it. If it does, it overwrites it!
    outputFile = fopen("sum.txt", "w");

    if (outputFile == NULL){
        printf("Error: Could not create sum.txt for writing!\n");
        return 1;
    }

    // 6. WRITE DATA TO THE FILE
    // fprintf works just like printf, but takes the FILE pointer as the first argument.
    fprintf(outputFile, "The total sum is: %d\n", sum);
    fprintf(outputFile, "Calculated automatically by the C program.\n");

    // 7. CLOSE THE OUTPUT FILE
    fclose(outputFile);

    printf("Result successfully saved to sum.txt!\n");

    return 0;
}