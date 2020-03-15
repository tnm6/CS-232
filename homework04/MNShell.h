#ifndef MNSHELL_H_
#define MNSHELL_H_

#include "Prompt.h"
#include "Path.h"
#include "CommandLine.h"
#include <unistd.h>
#include <string.h>

class MNShell
{
public:
  MNShell();
  void run();

private:
  Prompt prompt;
  Path path;

  void evaluateCmdLine(const CommandLine &cmdLine);
  void changeDir(const CommandLine &cmdLine);
  void forkProcess(const CommandLine &cmdLine, char *command);
  void runProgram(const CommandLine &cmdLine, char *command);
};

#endif