#include "PathTester.h"
#include "PromptTester.h"
#include "CommandLineTester.h"

int main() {
  PathTester pathTester;
  pathTester.run();

  PromptTester promptTester;
  promptTester.run();

  CommandLineTester clTester;
  clTester.runTests();
}