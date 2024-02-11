#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("pid : %d\n",getpid());
  void *ptr = sbrk(0);
  printf("program break :%p\n",ptr);
  getchar();
  printf("%ld\n",sizeof(int *));

  void *ptr1 = (void *)(ptr + (sizeof(int *)));
  brk(ptr1);
  ptr = sbrk(0);
  printf("program break :%p\n",ptr1);
  getchar();

  void *ptr2 = (void *)(ptr +(sizeof(int *)));
  brk(ptr2);
  ptr = sbrk(0);
  printf("program break :%p\n",ptr2);
  getchar();
}
