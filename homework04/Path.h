#ifndef PATH_H
#define PATH_H

class Path
{
public:
  Path();
  int find(const string& program) const;
  string getDirectory(int i) const;
};

#endif