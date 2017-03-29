#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void main()
{
 int fd;
 ssize_t nr;
 char buf[4096];

 fd = open("test", O_RDWR);
 nr = read(fd, buf, 4096);
 printf("buf: \n %s \n", buf);
 close(fd);
}