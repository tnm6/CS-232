#include "CommandLine.h"
#include <stdlib.h>
#include <vector>
#include <cstring>
// #include <iostream>
using namespace std;

//http://www.cplusplus.com/reference/istream/istream/get/
CommandLine::CommandLine(istream &in)
{
  // argc = 0;                            // init argc
  // int const size = 256;                // default size for input char array
  // char **ArgVector = new char *[size]; // init dummy argv
  // char *input = new char[size];        // input char array
  // char *point;

  // in.getline(input, size); // grab input

  // if (input != NULL)
  // {
  //   point = strtok(input, " "); // create pointer

  //   while (point != NULL)
  //   {
  //     ArgVector[argc] = point; // set argv to proper command
  //     argc++;                  // increment argc
  //     //cout << point << endl;
  //     point = strtok(NULL, " "); // move pointer
  //   }
  // }
  // argv = new char *;
  // argv = ArgVector;

  argc = 0;

  char *input = new char[CL_SIZE];
  char **tempVec = new char *[CL_SIZE];
  char *command;

  in.getline(input, CL_SIZE);

  command = strtok(input, " ");
  while (command != NULL)
  {
    tempVec[argc] = command;
    argc++;
    // cout << "Printing " << command << endl;
    command = strtok(NULL, " ");
  }

  argv = new char*;
  argv = tempVec;
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
  if (strcmp(argv[argc-1], "&") == 0)
  {
    return false;
  }
  return true;
}

CommandLine::~CommandLine()
{
  delete[] argv;
}