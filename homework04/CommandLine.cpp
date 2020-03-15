/*
CommandLine.cpp - class that reads a commandline
Written by: Marcos Hernandez (mah47) and Nathan Meyer
CS232 - Homework 4
March 14, 2020
*/



#include "CommandLine.h"
#include <stdlib.h>
#include <vector>
#include <cstring>
// #include <iostream>
using namespace std;

//http://www.cplusplus.com/reference/istream/istream/get/
CommandLine::CommandLine(istream &in)
{
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