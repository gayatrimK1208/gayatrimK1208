#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 
#define BUFSIZE 256    
// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
pid_t parent = getpid();
pid_t pid = fork();

    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Please provide the address of a file as an input.\n");
        return -1;
    }
    char cmd[BUFSIZE] = "wc -c < ";
// Usage of the strncat function allows to specify the maximum number of characters to append, ensuring you stay within bounds.
 if (argv[1] != NUL) {
    // Append argv[1] safely
    strncat(cmd, argv[1], BUFSIZE - strlen(cmd) - 1);
 } else {
    fprintf(stderr, "Error: Missing argument\n");
    return 1;
}   

 pid_t parent = getpid();
pid_t pid = fork();

if (pid == -1)
{
     fprintf(stderr, "Error: Fork not available");
} 
else if (pid > 0)
{
    int status;
    waitpid(pid, &status, 0);
}
else 
{
    // we are the child
    execve(cmd);
    _exit(EXIT_FAILURE);   // exec never returns
}
     // system(cmd); 
    
}
