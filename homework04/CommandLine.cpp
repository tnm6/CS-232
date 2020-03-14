#include "CommandLine.h"
#include <stdlib.h>
#include <vector>
using namespace std;

//http://www.cplusplus.com/reference/istream/istream/get/
CommandLine::CommandLine(istream &in)
{
  argc = 0;


  char *command;
  vector<char*> commandVec;

  while (in.peek() != '\n')
  {
    in >> command;
    commandVec.push_back(command);
    argc++;
  }

  char **argv = (char**) calloc (argc+1, sizeof(char*));

  for (int i = 0; i < argc; i++)
  {
    argv[i] = commandVec[i];
  }

  argv[argc] = NULL;
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
  for (int i = 0; i < argc; i++)
  {
    free(argv[i]);
  }

  free(argv);
}