#include <iostream>
#include <cerrno>
#include <cstdlib>

#include <sys/shm.h>

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

  while(true)
    {
      sharedArray[0] = 1;
      sharedArray[0] = 3 * sharedArray[0] +7; // should be 10
      if (sharedArray[0] != 10)
	cout << "Trouble, read value is " << sharedArray[0] << " but should be 10 " << endl;
    }
  
  return 0;
}
