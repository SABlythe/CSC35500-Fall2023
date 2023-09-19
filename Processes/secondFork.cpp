#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  int myPID = getpid();

  cout << "my original PID is" << myPID << endl;
  
  int newPID = fork();

  if (newPID == 0)
    cout << " I am the new child process" << endl;
  else
    cout << " Iam the original process, my child's PIS is " << newPID << endl;
  
  return 0;
}
