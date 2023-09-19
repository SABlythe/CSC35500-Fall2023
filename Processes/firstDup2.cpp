#include <cstdio>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
  FILE *fp=fopen(argv[1], "r");

  dup2(fileno(fp), fileno(stdin) );
  
  int var;
  cin >> var;
  while(cin)
    {
      cout << var * var << endl;
      cin >> var;
    }
  return 0;
}
