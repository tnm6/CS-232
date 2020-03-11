#include "Path.h"

Path::Path()
{
  char *fullPath;
  char *curPath;

  fullPath = getenv("PATH");

  curPath = strtok(fullPath, ":");
  while (curPath != NULL)
  {
    string curPathString(curPath);
    path.push_back(curPathString);
    curPath = strtok(NULL, ":");
  }
}