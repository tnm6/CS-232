#include "CommandLineTester.h"
#include <iostream>
using namespace std;

void CommandLineTester::run(istream &in) const
{
  CommandLine cl(in);

  for (int i = 0; i < cl.argc; i++)
  {
    cout << cl.argv[i] << endl;
  }
}
