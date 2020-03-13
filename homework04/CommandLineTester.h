#ifndef COMMAND_LINE_TESTER_H_
#define COMMAND_LINE_TESTER_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cassert>
using namespace std;

class CommandLineTester
{
public:
  void runTests() const;
  void testConstructor() const;
  void testgetCommand() const;
  void testgetArgCount() const;
  void testArgVector() const;
  void testnoAmpersand() const;
};

#endif //COMMAND_LINE_TESTER_H_