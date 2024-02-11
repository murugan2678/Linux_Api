#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("pid : %d\n",getpid());
  int x = 100;
  getchar();

  int *ptr = (int *)mmap(NULL, 2147487744, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
  *ptr = 100;
  printf("%d\n",*ptr);
  printf("%p\n",ptr);
  getchar();
}


/* output

murugan@HP:~/linux/malloc/9nov23$ cat /proc/7182/maps
5565b787d000-5565b787e000 r--p 00000000 08:06 786990                     /home/murugan/linux/virtual/a.out
5565b787e000-5565b787f000 r-xp 00001000 08:06 786990                     /home/murugan/linux/virtual/a.out
5565b787f000-5565b7880000 r--p 00002000 08:06 786990                     /home/murugan/linux/virtual/a.out
5565b7880000-5565b7881000 r--p 00002000 08:06 786990                     /home/murugan/linux/virtual/a.out
5565b7881000-5565b7882000 rw-p 00003000 08:06 786990                     /home/murugan/linux/virtual/a.out

5565b929d000-5565b92be000 rw-p 00000000 00:00 0                          [heap]
7fb2acfff000-7fb32d000000 rw-s 00000000 00:01 30842                      /dev/zero (deleted)

7fb32d000000-7fb32d028000 r--p 00000000 08:06 1443942                    /usr/lib/x86_64-linux-gnu/libc.so.6
7fb32d028000-7fb32d1bd000 r-xp 00028000 08:06 1443942                    /usr/lib/x86_64-linux-gnu/libc.so.6
7fb32d1bd000-7fb32d215000 r--p 001bd000 08:06 1443942                    /usr/lib/x86_64-linux-gnu/libc.so.6 */

