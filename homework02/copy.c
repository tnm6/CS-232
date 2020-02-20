#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>   // for access() to check if file exists
#include <sys/stat.h> // S_IS* macros

int main(int argc, char** argv) {
  if (argc != 3) {
    perror("\nERROR: Incorrect arguments. Usage: ./copy <src> <dest>\n\n");
    exit(-1);
  }

  struct stat stat_buf;

  char* src = argv[1];
  char* dest = argv[2];

  // Usage of stat struct based on: https://stackoverflow.com/q/230062
  if ( stat(src, &stat_buf) == 0 ) {  // file exists

  } else {
    perror("\nERROR: File not found. Exiting.\n\n");
    exit(-1);
  }


  // // Checks if file exists using access() based on this solution:
  // // https://stackoverflow.com/q/230062
  // if ( access(src, F_OK) == 0 ) {       // file exists
  //   if ( access(src, R_OK) == 0 ) {     // file is readable
  //     FILE * read = fopen(src, "r");    // open the file

  //     if ( access(dest, F_OK) == -1 ) { // file does not already exist

  //     } else {
  //       perror("\nERROR: Destination file already exists. Exiting.\n\n");
  //       exit(-1);
  //     }
  //   } else {
  //     perror("\nERROR: Insufficient read permissions. Exiting.\n\n");
  //     exit(-1);
  //   }
  // } else {
  //   perror("\nERROR: File not found. Exiting.\n\n");
  //   exit(-1);
  // }

  exit(0);
}