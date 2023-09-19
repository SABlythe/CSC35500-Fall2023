#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc, char *argv[])
{

  int pid = fork();

  if (pid!=0)
    {
      cout << "Parent, with pid = " << getpid()
	   << ", and (new) child pid = " << pid <<endl;

      int waitResult = waitpid(0, NULL, 0);
      cout << "tantrum over, waitpid() gave " << waitResult << endl;
    }
  else
    {
      cout << "Child, with pid = " << getpid() << endl;
      for (int i=0; i <10; i++)
	{
	  cout << i << ") I want my candy!!!" << endl;
	  sleep(1); // check to see what guardian does ....
	}
    }
  return 0; 
}
