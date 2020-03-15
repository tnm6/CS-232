/*
CommandLine.cpp - class that reads a commandline
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#include "CommandLine.h"
#include <stdlib.h>
#include <vector>
#include <cstring>
using namespace std;

/*
 * Constructor which takes input and parses it into variables argc and argv
 * If an ampersand is found, bool noAmp is set to false
 */
CommandLine::CommandLine(istream &in)
{
  argc = 0;
  noAmp = true;

  char *input = new char[CL_SIZE];
  char **tempVec = new char *[CL_SIZE];
  char *command;

  in.getline(input, CL_SIZE);

  command = strtok(input, " ");
  while (command != NULL)
  {
    if (strcmp(command, "&") == 0)
    {
      noAmp = false;
      break;
    }
    tempVec[argc] = command;
    argc++;
    command = strtok(NULL, " ");
  }

  argv = new char*;
  argv = tempVec;
  argv[argc] = NULL;  // make sure argv is null terminated
}

char* CommandLine::getCommand() const
{
  return argv[0];
}

int CommandLine::getArgCount() const
{
  return argc;
}

char** CommandLine::getArgVector() const
{
  return argv;
}

char* CommandLine::getArgVector(int i) const
{
  return argv[i];
}

bool CommandLine::noAmpersand() const
{
  return noAmp;
}

CommandLine::~CommandLine()
{
  delete[] argv;
}