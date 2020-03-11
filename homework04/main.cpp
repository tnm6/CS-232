#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
  char *fullPath;
  char *curPath;

  fullPath = getenv("PATH");

  curPath = strtok(fullPath, ":");
  while (curPath != NULL)
  {
    cout << curPath << endl;
    curPath = strtok(NULL, ":");
  }
}