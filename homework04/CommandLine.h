/*
CommandLine.h class that reads a commandline
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
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
  bool noAmp;
  friend class CommandLineTester;
};

#endif // COMMAND_LINE_H_