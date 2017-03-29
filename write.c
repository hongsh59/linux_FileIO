#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

void main()
{
 int fd;
 ssize_t nr;
 char buf[4096];
 
 const char *new = "add add";

 fd = open("test", O_WRONLY);
 nr = write(fd, new, strlen(new));
 close(fd);

 fd = open("test",O_RDONLY);
 nr = read(fd, buf, 4096);
 printf("buf: \n %s \n", buf);
 close(fd);
}
