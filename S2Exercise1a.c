#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }

    struct stat file_stat;

    // Get file status using stat function
    if (stat(argv[1], &file_stat) != 0) {
        perror("Error getting file stats");
        return -1;
    }

    // Print the size of the file in bytes
    printf("Size of the file '%s' is %ld bytes.\n", argv[1], file_stat.st_size);

    return 0;
}
