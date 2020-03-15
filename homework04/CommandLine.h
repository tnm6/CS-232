/*
CommandLine.h simulates a shell program
Written by: Marcos Hernandez (mah47) and Nathan Meyer
CS232 - Homework 4
March 14, 2020
*/




#ifndef COMMAND_LINE_H_
#define COMMAND_LINE_H_

#include <iostream>
using namespace std;

#define CL_SIZE 256

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