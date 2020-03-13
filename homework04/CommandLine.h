#ifndef COMMAND_LINE_H_
#define COMMAND_LINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

class CommandLine
{
public:
  char *commandInput;
  char **argv;
  int argc;
  CommandLine(istream &in);
  char *getCommand() const;
  int getArgCount() const;
  char **getArgVector() const;
  char *getArgVector(int i) const;
  bool noAmpersand() const;
  virtual ~CommandLine();
};

#endif //CommandLine