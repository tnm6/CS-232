#include "PromptTester.h"
#include <cassert>
#include <iostream>
using namespace std;

void PromptTester::run() const
{
  Prompt test;
  cout << "Testing Prompt class" << endl;
  testConstructor(test);
  testGet(test);
  cout << "Prompt tests passed" << endl;
}

void PromptTester::testConstructor(const Prompt &test) const
{
  cout << "\tTesting constructor" << endl;

  // Test specific to Nathan's MacBook
  assert(strcmp(test.workingDir, "/Users/nathan/CS/232/homework04") == 0);

  cout << "\tConstruct test passed" << endl;
}

void PromptTester::testGet(const Prompt &test) const
{

}