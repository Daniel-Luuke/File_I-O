#include <stdio.h>

int main(){
    // Trying to open a file that DOES NOT EXIST.
    FILE *myFile = fopen("missing_file.txt", "r");

    // WE ARE SKIPPING THE NULL CHECK!
    // myFile will be NULL, but we pretend everything is fine.

    char data[100];

    printf("Attempting to read from missing file...\n");

    // DEREFERENCING A NULL POINTER!
    // We are trying to read from a file pointer that points to nothing.
    fscanf(myFile, "%s", data);

    // The program will CRASH before it ever reaches this line.
    printf("Data read: %s\n", data);

    fclose(myFile);

    return 0;
}