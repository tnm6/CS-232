/*
Path.cpp finds directory paths for programs and commands, and handles them
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#include "Path.h"
#include <dirent.h>
#include <stdexcept>
#include <cstring>
using namespace std;

/*
 * Constructor which gathers PATH for device and parses out each entry
 */
Path::Path()
{
  char *fullPath;
  char *curPath;

  fullPath = getenv("PATH");  // get PATH for device

  // parse through PATH with delimiter ":"
  curPath = strtok(fullPath, ":");
  while (curPath != NULL)
  {
    directories.push_back(curPath);
    curPath = strtok(NULL, ":");
  }
}

/*
 * From a given string, searches each path for if program is present
 * Returns index of directory in which it is found
 * Else, returns -1
 */
int Path::find(const string &program) const
{
  DIR *dir;
  struct dirent *dirEntry;
  int i, numDirs;

  numDirs = directories.size(); // get numDirs for loop (to save time)
  for (i = 0; i < numDirs; i++)
  {
    dir = opendir(directories[i].c_str());    // open each directory

    while ((dirEntry = readdir(dir)) != NULL) // while there are entries
    {
      // check if the entry matches the program being searched for
      if (program.compare(dirEntry->d_name) == 0)
        return i;   // return index if found
    }

    closedir(dir);
  }

  return -1;
}

/*
 * Returns directory of given index i, if valid
 */
string Path::getDirectory(int i) const
{
  if (i < directories.size())
  {
    return directories[i];
  }
  else
  {
    throw out_of_range("Index out of range of directories");
  }
}