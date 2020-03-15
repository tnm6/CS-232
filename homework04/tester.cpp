/*
tester.cpp tests pathtester and prompttester
Written by: Marcos Hernandez (mah47) and Nathan Meyer
CS232 - Homework 4
March 14, 2020
*/



#include "PathTester.h"
#include "PromptTester.h"
// #include "CommandLineTester.h"
#include <iostream>
using namespace std;

int main() {
  PathTester pathTester;
  pathTester.run();

  PromptTester promptTester;
  promptTester.run();

  // CommandLineTester clTester;
  // clTester.run(cin);
}