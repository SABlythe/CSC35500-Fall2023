#include <iostream>
#include <cerrno>
#include <cstdlib>

#include <sys/sem.h>

// later, we need to specify how many semaphores are in the array
//   of semaphores that semget() will create ...
#define NUM_SEMS 1
#define NUM_COMMANDS 1

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
		      0);

  if (sem_id==-1)
    {
      // likely fails because semaphore does not exist ...
      // maybe add a semget() call to create it ???
      cerr << "semget() failed with errno = "
	   << errno << endl;
      return 2;
    }

  struct sembuf waitCommand[NUM_COMMANDS];

  waitCommand[0].sem_num = 0; // which semaphore in the array do we want?
  waitCommand[0].sem_op = -1; // decrement semaphore (by 1) and maybe wait   
  waitCommand[0].sem_flg = 0; // default flags ... 
  
  int semResult = semop(sem_id, waitCommand, NUM_COMMANDS );

  if (semResult==-1)
    {
      cerr << "semop() call failed." << endl;
      return 3;
    }
  
  return 0;
}
