#ifndef COMMAND_LINE_H_
#define COMMAND_LINE_H_

#include <iostream>
using namespace std;

class CommandLine
{
public:
  CommandLine(istream &in);
  char* getCommand() const;
  int getArgCount() const;
  char** getArgVector() const;
  char* getArgVector(int i) const;
  bool noAmpersand() const;
  virtual ~CommandLine();

private:
  char **argv;
  int argc;
  friend class CommandLineTester;
};

#endif //CommandLine