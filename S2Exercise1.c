#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
 int maxLength=getconf ARG_MAX;
 
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
// Usage of the strncat function allows to specify the maximum number of characters to append, ensuring you stay within bounds.
 if (argv[1] != NULL) {
    // Append argv[1] safely
    strncat(cmd, argv[1], BUFSIZE - strlen(cmd) - 1);
 } else {
    fprintf(stderr, "Error: Missing argument\n");
    return 1;
}   
      system(cmd); 
    
}
