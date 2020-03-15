/*
Prompt.cpp builds a prompt to be displayed in MNShell
Written by: Marcos Hernandez (mah47) and Nathan Meyer (tnm6)
CS232 - Homework 4, Prof. Victor Norman, Calvin University
March 14, 2020
IMPORTANT NOTE: Extension given by Prof. Norman
*/

#include "Prompt.h"
#include <unistd.h> // getcwd()

Prompt::Prompt()
{
  workingDir = getcwd(dirBuff, PATH_MAX);
}

char* Prompt::get() const
{
  return workingDir;
}