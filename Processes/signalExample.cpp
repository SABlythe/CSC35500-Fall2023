#include <iostream>
#include <signal.h>

using namespace std;

void myHandler(int sigNum)
{
  cout << "I am running!" << endl;
  cout << "received: " << sigNum << endl;
}

int main(int argc, char *argv[])
{
  signal (SIGSEGV, myHandler);

  if (fork()==0)
    {
      // in child ...
      cout << "started child" << endl;
      sleep(1);
      cout << "Ending child" << endl;
      return 0;
    }

  sleep(100);

  cout << "parent done!" << endl;
  return 0;
}


