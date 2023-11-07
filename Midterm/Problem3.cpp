#include <cstdio>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int pfd[2];
  int status = pipe(pfd);

  int pid = fork();
  if (pid==0) // child does grep (could have done awk)
    {
      FILE *fp =fopen("listings.txt", "r");
      dup2(fileno(fp), fileno(stdin) );
      dup2(pfd[1], fileno(stdout) );
      close(pfd[0]);
      char *args[3];
      args[0]="grep";
      args[1]="scifi";
      args[2]=NULL;
      execvp(args[0], args);
    }
  else // parent does awk (could have been grep)
    {
      dup2(pfd[0], fileno(stdin) );
      close(pfd[1]);
      char *args[4];
      args[0]="awk";
      args[1]="-f";
      args[2]="toLower";
      args[3]=NULL;
      execvp(args[0], args);
    }
    
  return 0;
}
