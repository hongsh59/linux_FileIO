#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main(){
        int fd;
        ssize_t nr;
        char buf[4096];

        const char *new = "add add\n";

        fd = open("./output.file", O_RDWR | O_CREAT | O_APPEND, 0777);
        nr = write(fd, new, strlen(new));
        close(fd);

        fd = open("./test", O_RDONLY, 0777);
        nr = read(fd, buf, 4096);
        printf("Write Operation is clear");
        close(fd);
}