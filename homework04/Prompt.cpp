/*
Prompt.cpp represents prompt commandline
Written by: Marcos Hernandez (mah47) and Nathan Meyer
CS232 - Homework 4
March 14, 2020
*/



#include "Prompt.h"
#include <unistd.h> // getcwd()

Prompt::Prompt()
{
  workingDir = getcwd(dirBuff, PATH_MAX);
}

char *Prompt::get() const
{
  return workingDir;
}