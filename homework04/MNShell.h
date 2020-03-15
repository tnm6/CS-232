/*
MNShell.h simulates a shell program
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#ifndef MNSHELL_H_
#define MNSHELL_H_

#include "Prompt.h"
#include "Path.h"
#include "CommandLine.h"

class MNShell
{
public:
  MNShell();
  void run();

private:
  Prompt prompt;
  Path path;

  void readCmdLine(const CommandLine &cmdLine);
  void printDir(const CommandLine &cmdLine);
  void changeDir(const CommandLine &cmdLine);
  void forkProcess(const CommandLine &cmdLine, char *command);
  void runProgram(const CommandLine &cmdLine, char *command);
};

#endif