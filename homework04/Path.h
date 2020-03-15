/*
Path.h finds directory paths for programs and commands, and handles them
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#ifndef PATH_H
#define PATH_H

#include <string>
#include <vector>
using namespace std;

class Path
{
public:
  Path();
  int find(const string &program) const;
  string getDirectory(int i) const;

private:
  vector<string> directories;
  friend class PathTester;
};

#endif