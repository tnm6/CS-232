#include "Path.h"
#include <dirent.h>

Path::Path()
{
  readPath();
}

int Path::find(const string &program) const
{
  DIR *dir;
  struct dirent *dirEntry;
  int i, numDirs;

  numDirs = directories.size();
  for (i = 0; i < numDirs; i++)
  {
    dir = opendir(directories[i].c_str());

    while ((dirEntry = readdir(dir)) != NULL)
    {
      if (program.compare(dirEntry->d_name) == 0)
        return i;
    }

    closedir(dir);
  }

  return -1;
}

string Path::getDirectory(int i) const
{
  if (i < directories.size())
    return directories[i];
  else
    throw "Index out of range of directories";
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