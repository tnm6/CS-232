#include "Path.h"
#include <dirent.h>

Path::Path()
{
  readPath();
}

int Path::find(const string &program) const
{
  DIR *currentDirectory;
  struct dirent *dirEntry;
  int i, numDirs;

  numDirs = directories.size();
  for (i = 0; i < numDirs; i++)
  {
    currentDirectory = opendir(directories[i].c_str());

    while ((dirEntry = readdir(currentDirectory)) != NULL)
    {
      if (strcmp(dirEntry->d_name, program.c_str()) == 0)
        return i;
    }

    closedir(currentDirectory);
  }

  return -1;
}

string Path::getDirectory(int i) const
{
  if (i < directories.size())
    return directories[i];
  else
    throw "Index out or range of directories";
}

void Path::readPath()
{
  char *fullPath;
  char *curPath;

  fullPath = getenv("PATH");

  curPath = strtok(fullPath, ":");
  while (curPath != NULL)
  {
    directories.push_back(curPath);
    curPath = strtok(NULL, ":");
  }
}