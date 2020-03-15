/*
Prompt.h builds a prompt to be displayed in MNShell
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#ifndef PROMPT_H
#define PROMPT_H

#include <limits.h>

class Prompt
{
public:
  Prompt();
  char* get() const;

private:
  char dirBuff[PATH_MAX];
  char *workingDir;
};

#endif