#include "MNShell.h"
#include "CommandLine.h"
#include <iostream>
#include <string>
using namespace std;

MNShell::MNShell()
{
  // path = Path();
  // prompt = Prompt();
}

void MNShell::run()
{
  while (true)
  {
    cout << prompt.get() << "$ " << flush;
    CommandLine mn(cin);

    char *command = mn.getCommand();

    if (mn.getArgCount() > 0)
    {
      if (strcmp(command, "exit") == 0)
      {
        cout << "Leaving now..." << endl;
        break;
      }
      if (strcmp(command, "pwd") == 0)
      {
        cout << endl << prompt.get() << endl;
        continue;
      }
      if (strcmp(command, "cd") == 0)
      {
        int userCommand = chdir(mn.getArgVector(1));
        if (userCommand == -1)
        {
          cout << "Directory not found..." << endl;
        }
        // else
         //{
          // Prompt;
        // }
        continue;
      }
      if (path.find(command) == -1)
      {
        cout << "Command does not exist...." << endl;
      }
      else
      {
        pid_t readCommand = fork();
        if (readCommand == -1)
        {
          cout << "Failed..." << endl;
        }
        if (readCommand == 0)
        {
          int comm = path.find(command);
          string forkcomm = path.getDirectory(comm) + "/" + mn.getCommand();
          char **forkcomm2 = mn.getArgVector();
          forkcomm[mn.getArgCount()] = NULL;
          execve(forkcomm.c_str(), forkcomm2, NULL);
        }

        int result;
        if (mn.noAmpersand())
        {
          waitpid(readCommand, &result, 0);
        }
      }
    }
  }
}

/*
 MNShell::~MNShell()
{
     path.~Path();
     prompt.~Prompt();
}
*/
