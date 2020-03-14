#ifndef MNSHELL_H_
#define MNSHELL_H_

#include "Prompt.h"
#include "Path.h"
#include <unistd.h>
#include <string>

class MNShell
{
public:
  MNShell();
  void run();

private:
  Prompt prompt;
  Path path;
};

#endif