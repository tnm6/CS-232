#include 'ShellCommandShell.h'

ShellCommandLine::ShellCommandLine(istream& in){
    char shell;
    while (in.get(shell)){
        if(shell == ' '){
            argc++;
            commandInput += shell;
        }
    }

    argv = getArVector();
}

char* ShellCommandLine::getCommand() const{
    return argv[0];
}

int ShellCommandLine::getArgCount() const{
    return argc;
}

char** ShellCommandLine::getArgVector() const {
    return argv;
    //add me
}

char* ShellCommandLine::getArgVector(int i) const{
    return argv[i];
}


bool ShellCommandLine::noAmpersand() const{
    return (comandInput, '&');
}

ShellCommandLine::~ShellCommandShell(){
    free(argv);
}