#include <iostream>
#include <cerrno>
#include <cstdlib>

#include <sys/sem.h>
#include <sys/shm.h>

using namespace std;

#define NUM_SEMS 1

int main(int argc, char *argv[])
{
  if (argc!=3)
    {
      cerr << "USAGE: " << argv[0] << " <shm key number> <sem key number>"
	   << endl;
      return 1;
    }

  // begin: shared memory code
  int myKeyVal = atoi(argv[1]);

  int shm_id = shmget(myKeyVal, 1024 /*1 KB*/, 0);

  if (shm_id==-1)
    {
      cerr << "shmget() failed with errno = "
	   << errno << endl;
      return 2;
    }

  
  int *sharedArray = (int *) shmat(shm_id, NULL, 0);

  if (sharedArray == (int *) -1)
    {
      cerr << "shmat() failed " << endl;
      return 3;
    }


  /// begin: semaphore code 
  
  myKeyVal = atoi(argv[2]);

  int sem_id = semget(myKeyVal, NUM_SEMS,
                      0);

  if (sem_id==-1)
    {
      sem_id = semget(myKeyVal, NUM_SEMS,
                      IPC_CREAT|IPC_EXCL|0666);
      semctl(sem_id, 0 /*index #*/,   SETVAL, 1); 
      if (sem_id==-1)
	{
	  cerr << "semget() failed with errno = "
	       << errno << endl;
	  return 2;
	}
    }



  while(true)
    {
      // wait
      struct sembuf command[1];
      command[0].sem_num = 0;
      command[0].sem_op  =-1;
      command[0].sem_flg = 0;
      semop(sem_id, command, 1);

      //cout << "ABOUT TO GETINTO MY CRitical section .... " << endl;
      
      // begin critical section
      sharedArray[0] = 1;
      sharedArray[0] = 3 * sharedArray[0] +7; // should be 10
      if (sharedArray[0] != 10)
	cout << "Trouble, read value is " << sharedArray[0] << " but should be 10 " << endl;
      // end critical section

      //signal
      command[0].sem_num = 0;
      command[0].sem_op  =+1;
      command[0].sem_flg = 0;
      semop(sem_id, command, 1);
    }
  
  return 0;
}
