#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

// run    ls -l | wc
int main(int argc, char *argv[])
{
  int pipeInfo[2];
  int myPipe = pipe(pipeInfo);
  int pid = fork();
  if (pid!=0) // this is the parent, run "wc"
    {
      // attach parent input to reader end of pipe. 
      dup2(pipeInfo[0] , fileno(stdin));
      close(pipeInfo[1]); // wc will not be writing to the pipe. 
      
      //char *args[2]; 
      char* *args= new char*[2];

      string command("wc");
      args[0] = new char[command.length()+1];
      strcpy(args[0], command.c_str());

      args[1]=NULL;

      execvp(args[0], args);
    }
  else //(pid==0) so this is the child, run "ls -l"
    {
      dup2(pipeInfo[1] , fileno(stdout));
      close(pipeInfo[0]); // ls -l will not read from pipe
      char *args[3]; args[0]= "ls"; args[1]="-l"; args[2]=NULL;
      execvp(args[0], args);
    }
  return 0;
}
