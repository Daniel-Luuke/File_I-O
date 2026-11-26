#include <stdio.h>
#include <errno.h>  // Required for errno
#include <string.h> // Required for strerror

// Function that returns a status code (0 for success, 1 for failure)
int readFileWithReturnCode(const char *filename){
    FILE *file = fopen(filename, "r");

    if (file == NULL){
        // EVALUATION:
        // Instead of throwing an exception, we print to the standard ERROR stream (stderr).
        // stderr is separate from normal stdout and is used specifically for errors.
        // errno is a global variable set by C when an error occurs.
        // strerror translates the error number into a readable string.
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));

        // We return a 1 to signal to the caller that it failed.
        return 1;
    }

    // ... read file ...

    fclose(file);
    return 0; // Return 0 for success
}

int main(){
    printf("--- Testing Return Code Strategy ---\n");

    // We must manually check the return code (1 = fail)
    if (readFileWithReturnCode("data.txt") == 1){
        printf("Main function: Handled error gracefully. Program continues.\n");
    }

    printf("\n--- Evaluation ---\n");
    printf("In C, we must manually check return codes.\n");
    printf("If the programmer forgets to check, the program might crash later.\n");

    return 0;
}