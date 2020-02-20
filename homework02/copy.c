#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>   // for access() to check if file exists
#include <sys/stat.h> // S_IS* macros

int main(int argc, char** argv) {
  if (argc != 3) {
    perror("\nERROR: Incorrect arguments. Usage: ./copy <src> <dest>\n\n");
    exit(-1);
  }

  char* src = argv[1];
  char* dest = argv[2];

  struct stat stat_buf;

  // Usage of stat struct based on:
  // https://stackoverflow.com/a/230070 && https://stackoverflow.com/a/3828537
  if ( stat(src, &stat_buf) == 0 ) {    // file exists
    if ( S_ISREG(stat_buf.st_mode) ) {    // file is regular
      exit(0);
    } else {
      perror("\nERROR: <src> not regular file. Exiting.\n\n");
      exit(-1);
    }
  } else {
    perror("\nERROR: File not found. Exiting.\n\n");
    exit(-1);
  }

  exit(0);
}