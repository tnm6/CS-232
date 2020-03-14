#include "CommandLine.h"
#include <limits.h>
#include <stdlib.h>
#include <vector>
using namespace std;


//alright

// 
// cool I just installed it, but I have to restart VS Code real quick

//http://www.cplusplus.com/reference/istream/istream/get/
CommandLine::CommandLine(istream &in)
{
  argc = 0;

  char *input;
  char *command;
  vector<char*> commands;

  input = (char*) calloc (ARG_MAX, sizeof(char));

  command = strtok(input, " ");
  while (strcmp(command, "\0") != 0)
  {
    argc++;
    commands.push_back(command);
  }

  argv = (char**) calloc (argc, sizeof(char));

  for (int i = 0; i < argc; i++)
  {
    argv[i] = commands[i];
  }

  free(input);
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
  if (strcmp(argv[argc-1], "&"))
  {
    return false;
  }
  return true;
}

CommandLine::~CommandLine()
{
  free(argv);
}