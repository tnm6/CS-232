#ifndef PROMPT_H
#define PROMPT_H

#include <limits.h>

class Prompt
{
public:
  Prompt();
  char *get() const;

private:
  char dirBuff[PATH_MAX];
  char *workingDir;
  friend class PromptTester;
};

#endif