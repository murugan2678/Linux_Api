#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("pid :%d\n",getpid());
  void *ptr = sbrk(0);
  printf("program break %p\n",ptr);
  getchar();
}
