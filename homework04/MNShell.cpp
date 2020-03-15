/*
MNShell.cpp simulates a shell program
Written by: Marcos Hernandez (mah47) and Nathan Meyer
CS232 - Homework 4
March 14, 2020
*/



#include "MNShell.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

MNShell::MNShell()
{
}

void MNShell::run()
{
  while (true)
  {
    cout << prompt.get() << "$ " << flush;
    CommandLine cmdLine(cin);
    evaluateCmdLine(cmdLine);
  }
}

void MNShell::evaluateCmdLine(const CommandLine &cmdLine)
{
  char *command = cmdLine.getCommand();

  if (cmdLine.getArgCount() > 0)
  {
    if (strcmp(command, "exit") == 0)
    {
      cout << "Leaving now..." << endl;
      exit(0);
    }
    else if (strcmp(command, "pwd") == 0)
    {
      cout << prompt.get() << endl;
    }
    else if (strcmp(command, "cd") == 0)
    {
      changeDir(cmdLine);
    }
    else if (path.find(command) == -1)
    {
      cout << "Command does not exist...." << endl;
    }
    else
    {
      forkProcess(cmdLine, command);
    }
  }
}

void MNShell::changeDir(const CommandLine &cmdLine)
{
  char *newDir = cmdLine.getArgVector(1);
  if (chdir(newDir) == -1)
  {
    cerr << "Invalid directory" << endl;
  }
  else
  {
    prompt = Prompt();
  }
}

void MNShell::forkProcess(const CommandLine &cmdLine, char *command)
{
  pid_t child_process;
  child_process = fork();

  if (child_process < 0)
  {
    cerr << "Forking process failed..." << endl;
  }
  else if (child_process == 0)
  {
    runProgram(cmdLine, command);
  }
  else
  {
    if (cmdLine.noAmpersand())
    {
      waitpid(child_process, NULL, 0);
    }
  }
}

void MNShell::runProgram(const CommandLine &cmdLine, char *command)
{
  string cmd(command); // convert char* command to string
  int pathIndex = path.find(cmd);
  if (pathIndex == -1)
  {
    cerr << "Command not found..." << endl;
  }
  else
  {
    string cmdPath = path.getDirectory(pathIndex) + "/" + cmd;
    execve(cmdPath.c_str(), cmdLine.getArgVector(), NULL);

    // Error message if execve does not return
    cerr << command << " failed..." << endl;
  }
}
