#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define BUFF_SIZE 1024
int main(int argc , char *argv[]) {
    int srcfd,destfd,nread,nwrite;
    char buff[BUFF_SIZE];
    if (argc != 3) {
        printf("Usage : cpcmd source_file dest_file\n");
        exit(EXIT_FAILURE);
    }
    srcfd = open(argv[1],O_RDONLY);
    if (srcfd == -1) {
        perror("Error opening the source file\n");
        exit(EXIT_FAILURE);
    }
    destfd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR);
    if (destfd == -1 ) {
        perror("Error opening the destination file\n");
        close(destfd);
        exit(EXIT_FAILURE);
    }

    while ((nread = read(srcfd,buff,BUFF_SIZE))>0) {
        printf("%d",nread);
        nwrite = write(destfd,buff,nread);
        if (nread != nwrite) {
            printf("Error writing the file\n");
            close(srcfd);
            close(destfd);
            exit(EXIT_FAILURE);
        }
    }
    if (nread == -1) {
        perror("Error reading from the file\n");
    }
    if (close(srcfd) == -1) {
        perror("Error closing the source file");
    }
    if (close(destfd) == -1) {
        perror("Error closing the destination file");
    }
    return 0;
}