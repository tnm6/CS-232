#ifndef PROMPTTESTER_H_
#define PROMPTTESTER_H_

#include "Prompt.h"

class PromptTester
{
public:
  void run() const;
private:
  void testConstructor(const Prompt &test) const;
  void testGet(const Prompt &test) const;
};

#endif