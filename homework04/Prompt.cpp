#include "Prompt.h"
#include <unistd.h> // getcwd()

Prompt::Prompt()
{
  workingDir = getcwd(dirBuff, PATH_MAX);
}

char *Prompt::get() const
{
  return workingDir;
}