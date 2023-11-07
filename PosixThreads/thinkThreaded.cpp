#include <iostream>

#include <pthread.h>

using namespace std;

pthread_t thread1, thread2;

void* doThread(void *arg)
{
  int *myPtr = (int *) arg;

  for (int i=0; i<100; i++)
    {
      cout << "Thread " << *myPtr << endl;
    }
  
  return NULL;
}

int main(int argc, char *argv[])
{
  int *id1=new int(1);
  int errCode = pthread_create(&thread1, NULL, doThread, (void *) id1);
  if (errCode==-1)
    cerr << "pthreadcreate() failed " << endl;

  id1=new int(2);
  errCode = pthread_create(&thread2, NULL, doThread, (void *) id1);
  if (errCode==-1)
    cerr << "pthreadcreate() failed " << endl;

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);
  return 0;
}
