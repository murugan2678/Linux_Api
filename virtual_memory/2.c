#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main()
{
  printf("system default page : %ld\n",sysconf(_SC_PAGESIZE));
  printf("system default _SC_CHILD_MAX : %ld\n",sysconf(_SC_CHILD_MAX));
}
