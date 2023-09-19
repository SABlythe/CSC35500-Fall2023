#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  int myPID = getpid();

  cout << "my original PID is" << myPID << endl;
  
  int newPID = fork();
  
  cout << "my new PID is " << newPID << endl;
  
  return 0;
}
