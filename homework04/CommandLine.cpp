#include "CommandLine.h"
#include <stdlib.h>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

//http://www.cplusplus.com/reference/istream/istream/get/
CommandLine::CommandLine(istream &in)
{
  argc = 0;

  char **argv = new char*[CL_SIZE];
  char *input = new char[CL_SIZE];
  char *command;

  in.getline(input, CL_SIZE);

  command = strtok(input, " ");
  while (command != '\0')
  {
    // argv[argc] = command;
    argc++;
    cout << "Printing " << command << endl;
    command = strtok(NULL, " ");
  }

  // char *command;
  // vector<char*> commandVec;

  // // ***this loop is causing the bus error/segmentation fault***
  // while (in.peek() != '\n')
  // {
  //   in >> command;
  //   commandVec.push_back(command);
  //   argc++;
  // }

  // char **argv = (char**) calloc (argc+1, sizeof(char*));

  // for (int i = 0; i < argc; i++)
  // {
  //   argv[i] = commandVec[i];
  // }

  // argv[argc] = NULL;
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

// CommandLine::~CommandLine()
// {
//   for (int i = 0; i < argc; i++)
//   {
//     free(argv[i]);
//   }

//   free(argv);
// }