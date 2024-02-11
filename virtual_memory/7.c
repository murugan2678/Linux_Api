#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int *sum;
#define ONE_GB 1073741824
int main()
{
  int x;
  pid_t pid;
  pid = fork();

  //void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
  //int *ptr = (int *)mmap(NULL, 2147487744, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
  
  if(pid == -1)
  {
    printf("error opening the fork\n");
  }
  else if(pid > 0)
  {
    printf("parent process : %d\n",getpid());
    wait(NULL);
    getchar();
  }
  else if(pid == 0)
  {
    printf("child process\n");
    printf("pid :%d\n",getpid());
    int *ptr = (int *)mmap(NULL, 2147487744, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
   // int *ptr = (int *)mmap(NULL, ONE_GB, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
    printf("%p\n",ptr);
    //*sum = 100;
    perror("child :");
    getchar();
  }
}
