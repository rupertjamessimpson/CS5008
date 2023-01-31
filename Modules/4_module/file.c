#include <stdio.h>

int main() {
    FILE* filePointer;

    // first arg is data we want to read.
    // Second is operation 'r' for read and 'w' for write
    filePointer = fopen("data.txt", "r");

    int buffer;

    // While not at end of file, read contents.
    // while(!feof(filePointer)) {
    //     fscanf(filePointer, "%d", &buffer);
    //     printf("I read: %d\n", buffer);
    // }

    while(1 == fscanf(filePointer, "%d", &buffer)) {
        printf("I read: %d\n", buffer);
    }

    // Must close file
    fclose(filePointer);

    return 0;
}