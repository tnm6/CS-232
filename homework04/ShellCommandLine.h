#ifndef ShellCommandLine_H_
#define ShellCommandLine_H_

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;

class ShellCommandLine{
    public:
        ShellCommandLine(istream& in);
        char* getCommand() const;
        int getArgCount() const;
        char** getArgVector() const;
        bool noAmpersand() const;
        virtual ~CommandLine();

        char* commandInput;
        char** argv;
        int argc;
};

#endif