#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  int myPID = getpid();

  cout << "my pid is " << myPID << endl;
  
  return 0;
}
