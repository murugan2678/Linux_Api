#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("pid :%d\n",getpid());
  void *ptr = sbrk(0);
  printf("program break :%p\n",ptr);
  getchar();

  void *mptr1 = malloc((sizeof(int *)));
  printf("int pointer :%p\n",mptr1);
  getchar();

  void *mptr2 = malloc((1<<31));
  printf("%p\n",mptr2);
  getchar();

  ptr = sbrk(0);
  printf("program break : %p\n",ptr);
  getchar();
}
