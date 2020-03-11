#ifndef PATHTESTER_H_
#define PATHTESTER_H_

#include "Path.h"

class PathTester
{
public:
  void run() const;
private:
  void testConstructor(const Path &test) const;
  void testFind(const Path &test) const;
  void testGetDir(const Path &test) const;
};

#endif