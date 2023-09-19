#include <cstring>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  // attempt to run "ls -la"
  //   2 arguments:
  //  [0] = "ls"
  //  [1] = "-la"
  //  [2] = NULL
  char* array[3];
  array[0] = new char[100]; strcpy( array[0],  "ls");
  array[1] = new char[100]; strcpy( array[1],  "-la");
  array[2] = NULL;
  
  execvp( array[0], array );

  cout << "ALL DONE COMMAND" << endl;
  
  return 0; 
}
