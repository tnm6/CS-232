/*
MNShell.cpp simulates a shell program
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#include "MNShell.h"
#include <iostream>   // cout, ...
#include <cstring>    // strcmp(), ...
#include <cstdlib>    // exit(), ...
#include <sys/wait.h> // waitpid(), ...
#include <unistd.h>   // fork(), execve(), ...
using namespace std;

MNShell::MNShell() // empty "stub" constructor
{
}

/* 
 * Initializes the shell
 */
void MNShell::run()
{
  while (true)
  {
    cout << prompt.get() << "$ " << flush;
    CommandLine cmdLine(cin);
    readCmdLine(cmdLine);
    prompt = Prompt(); // refresh prompt (just in case)
  }
}

void MNShell::readCmdLine(const CommandLine &cmdLine)
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
      cerr << "Command does not exist...." << endl;
    }
    else
    {
      forkProcess(cmdLine, command);
    }
  }
}

void MNShell::printDir(const CommandLine &cmdLine)
{
  if (cmdLine.getArgCount() != 1)
  {
    cerr << "Invalid usage (use \"pwd\")..." << endl;
  }
  else
  {
    cout << prompt.get() << endl;
  }
}

void MNShell::changeDir(const CommandLine &cmdLine)
{
  if (cmdLine.getArgCount() != 2) // check for correct arguments
  {
    cerr << "Invalid usage (use \"cd <directory>\")..." << endl;
  }
  else
  {
    char *newDir = cmdLine.getArgVector(1);
    if (chdir(newDir) == -1)
    {
      cerr << "Invalid directory" << endl;
    }
  }
}

void MNShell::forkProcess(const CommandLine &cmdLine, char *command)
{
  pid_t childProcess;    // declare...
  childProcess = fork(); // and fork a new process

  if (childProcess < 0)
  {
    cerr << "Forking process failed..." << endl;
  }
  else if (childProcess == 0) // process is parent, so run
  {
    runProgram(cmdLine, command);
  }
  else if (cmdLine.noAmpersand()) // process is child, wait if not given '&'
  {
    waitpid(childProcess, NULL, 0);
  }
}

void MNShell::runProgram(const CommandLine &cmdLine, char *command)
{
  string cmd(command);            // convert cstring command to string
  int pathIndex = path.find(cmd); // get index for directory containing command
  if (pathIndex == -1)
  {
    cerr << "Command not found..." << endl;
  }
  else
  {
    // build string of full path with command
    string cmdPath = path.getDirectory(pathIndex) + "/" + cmd;
    // and run it
    execve(cmdPath.c_str(), cmdLine.getArgVector(), NULL);

    // Error message if execve does not return
    cerr << command << " failed..." << endl;
  }
}
