#include <iostream>
#include <cerrno>
#include <cstdlib>

#include <sys/sem.h>

// later, we need to specify how many semaphores are in the array
//   of semaphores that semget() will create ...
#define NUM_SEMS 1

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2)
    {
      cerr << "USAGE: " << argv[0] << " <key number>"
	   << endl;
      return 1;
    }

  int myKeyVal = atoi(argv[1]);

  int sem_id = semget(myKeyVal, NUM_SEMS,
		      IPC_CREAT|IPC_EXCL|0666);

  if (sem_id==-1)
    {
      cerr << "semget() failed with errno = "
	   << errno << endl;
      return 2;
    }
  
  return 0;
}
