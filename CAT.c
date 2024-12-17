#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[]) {
    int fd,i;
    char buff[2];
    fd = open(argv[1],O_RDONLY,0777);
    if (fd == -1) {
        printf("Error opening the file\n");
    }
    else {
        while((i=read(fd,buff,1))>0) {
            printf("%c",buff[0]);
        }
        close(fd);
    }
}