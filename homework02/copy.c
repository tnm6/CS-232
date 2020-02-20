#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>   // for access() to check if file exists

int main(int argc, char** argv) {
  if (argc != 3) {
    perror("\nERROR: Incorrect arguments. Usage: ./copy <src> <dest>\n\n");
    return -1;
  }

  char* src = argv[1];
  char* dest = argv[2];

  // Checks if file exists using access() based on this solution:
  // https://stackoverflow.com/q/230062
  if ( access(src, F_OK) != -1 ) {
    printf("\nReading file %s...\n", src);
    
    if ( access(src, R_OK) != -1 ) {
      ;
    } else {
      perror("\nERROR: Insufficient read permissions. Exiting.\n\n");
      return -1;
    }

  } else {
    perror("\nERROR: File not found. Exiting.\n\n");
    return -1;
  }

  return 0;
}