#include "PathTester.h"
#include "PromptTester.h"
#include "CommandLineTester.h"
#include <iostream>
using namespace std;

int main() {
  PathTester pathTester;
  pathTester.run();

  PromptTester promptTester;
  promptTester.run();

  CommandLineTester clTester;
  clTester.run(cin);
}