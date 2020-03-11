#ifndef PATH_H
#define PATH_H

#include <string>
#include <vector>
using namespace std;

class Path
{
public:
  Path();
  int find(const string& program) const;
  string getDirectory(int i) const;

private:
  vector<string> path;
};

#endif