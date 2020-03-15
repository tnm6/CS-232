/*
CommandLineTester.cpp tests commandline
Written by: Marcos Hernandez (mah47) and Nathan Meyer
CS232 - Homework 4
March 14, 2020
*/


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
