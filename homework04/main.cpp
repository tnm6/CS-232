#include "Path.h"
#include <iostream>
using namespace std;

int main()
{
  Path myPath;

  cout << myPath.find("zsh") << endl;
  cout << myPath.find("md5") << endl;
}