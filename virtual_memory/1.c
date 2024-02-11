#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

#define ONE_GB (1<<30)
int main()
{
  int count = 0;
  printf("pid : %d\n",getpid());
  getchar();
  for(; ;)
  {
    if(malloc (ONE_GB) == NULL)
    {
      printf("out of memory\n");
      exit(-1);
    }
    else
    {
      sleep(1);
      count++;
      printf("total %d GB assigned\n",count);
    }
  }
}
