#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main(){
        int fd;
        ssize_t nr;
        int pos;

        off_t ret1, ret2;
        char buf[4098];
        char *new1 = "ABC123\n";
        char *new2 = "DEF45654\n";
        char *new3 = "GHI789\n";

        fd = open("./output.file", O_WRONLY | O_CREAT | O_APPEND, 0755);
        nr = write(fd, new1, strlen(new1));

        ret1 = lseek(fd, (off_t) 4 ,SEEK_SET);
        nr = write(fd, new2, strlen(new2));

        pos = lseek(fd, 0, SEEK_CUR);
        printf("now is in %d\n", pos);

        ret2 = lseek(fd, 0, SEEK_END);
        nr = write(fd, new3, strlen(new3));

        pos = lseek(fd, 0, SEEK_CUR);
        printf("now is in %d\n", pos);

        close(fd);
}