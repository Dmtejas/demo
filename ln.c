#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <srcfile> <destfile>\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if (link(argv[1],argv[2]) == -1) {
        perror("Link error\n");
        return 1;
    }
    printf("Files Linked\n");
    printf("Inode number of files linked\n");

    char str[100];
    sprintf(str,"dir \b %s %S ",argv[1],argv[2]);
    system(str);
    return 0;
}