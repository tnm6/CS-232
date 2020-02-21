/**
 * homework02
 * Simple binary copying program using POSIX commands to copy file src to dest
 * 
 * CS-232, Calvin University, Professor Victor Norman
 * @author  Nathan Meyer
 * @date    2/20/2020
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h> // stat struct and S_ISREG macro

int main(int argc, char** argv) {
  // First check for correct number of args
  if (argc != 3) {
    fprintf(stderr, "ERROR: Incorrect arguments. "
            "Usage: ./copy <src> <dest>\n");
    exit(-1);
  }

  // read args for src and dest addresses
  char *src = argv[1];
  char *dest = argv[2];

  // stat struct buffer to check if src is regular
  struct stat stat_buf;

  // Usage of stat struct based on:
  // https://stackoverflow.com/a/230070 && https://stackoverflow.com/a/3828537
  if ( lstat(src, &stat_buf) == 0 ) {     // src file exists
    if ( S_ISREG(stat_buf.st_mode) ) {    // src file is regular
      // Open file streams to read and write from
      FILE *read = fopen(src, "r");
      FILE *write = fopen(dest, "wx");

      // "wx" based check from:
      // https://www.geeksforgeeks.org/fopen-for-an-existing-file-in-write-mode
      if ( write != NULL ) {    // dest file does not already exist
        int ch = fgetc(read);   // read first char from file

        // based on:
        // https://www.tutorialspoint.com/c_standard_library/c_function_fputc.htm
        while ( !feof(read) ) { // write until end-of-file
          fputc(ch, write);
          ch = fgetc(read);
        }
      } else {
        fprintf(stderr, "ERROR: <dest> file already exists\n");
        exit(-1);
      }
    } else {
      fprintf(stderr, "ERROR: <src> not a regular file "
              "(directory, symlink, etc.)\n");
      exit(-1);
    }
  } else {
    fprintf(stderr, "ERROR: <src> file not found\n");
    exit(-1);
  }

  exit(0);  // exit normally if all goes well
}
