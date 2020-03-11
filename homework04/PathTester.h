#ifndef PATHTESTER_H_
#define PATHTESTER_H_

#include "Path.h"

class PathTester
{
public:
  void run() const;
private:
  void testConstructor() const;
  void testFind() const;
  void testGetDir() const;
};

#endif