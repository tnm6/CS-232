#include "Prompt.h"
#include <unistd.h> // getcwd()

Prompt::Prompt()
{
  workingDir = getcwd(dirBuff, PATH_MAX + 1);
}

char *Prompt::get() const
{
  return workingDir;
}