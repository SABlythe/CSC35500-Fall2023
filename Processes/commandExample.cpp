#include <cstdio>
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
      char *args[2]; args[0]= "wc"; args[1]=NULL;
      execvp(args[0], args);
    }
  else //(pid==0) so this is the child, run "ls -l"
    {
      char *args[3]; args[0]= "ls"; args[1]="-l"; args[2]=NULL;
      execvp(args[0], args);
    }
  return 0;
}
