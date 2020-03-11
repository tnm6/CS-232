#include "Path.h"

Path::Path()
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

int Path::find(const string &program) const
{
  DIR *currentDirectory;
  struct dirent *dirEntry;
  int i, length;

  length = directories.size();
  for (i = 0; i < length; i++)
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
  return directories[i];
}