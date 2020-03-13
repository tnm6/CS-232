#include "CommandLine.h"

//http://www.cplusplus.com/reference/istream/istream/get/
CommandLine::CommandLine(istream &in)
{
  char shell;
  //function split str into tokens
  char *vectorArg = strtok(commandInput, " ");
  int vec = 0;
  if (shell != NULL)
  {
    while (in.get(shell))
    {
      if (shell == ' ')
      {
        argc++;
        commandInput += shell;
      }
    }
  }

  while (vectorArg != NULL)
  {
    cout << vectorArg << flush;
    //malloc returns pointer to the uninitialized memory block
    argv[vec] = vectorArg;
    argv[vec] = (char *)malloc((sizeof(vectorArg)));
    vec++;
  }
  argv = getArgVector();
}

char *CommandLine::getCommand() const
{
  return argv[0];
}

int CommandLine::getArgCount() const
{
  return argc;
}

char **CommandLine::getArgVector() const
{
  return argv;
}

char *CommandLine::getArgVector(int i) const
{
  return argv[i];
}

bool CommandLine::noAmpersand() const
{
  bool cancelAmpersand = true;
  string Ampersand(commandInput);
  if (Ampersand.find("&") != string::npos)
  {
    cancelAmpersand = false;
  }
  return cancelAmpersand;
}

CommandLine::~CommandLine()
{
  delete[] argv;
}