#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "debug.h"




void print0(size_t count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(stderr, "0");
    }
    fprintf(stderr, "\n");
}

void print1(size_t count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(stderr, "1");
    }
    fprintf(stderr, "\n");
}

void parent()
{
    int i = 100;


    while(i--)
    {
        print0(10);
    }
}

void child()
{
    int i = 100;

    while(i--)
    {
        print1(10);
    }
}



int main(void)
{
    pid_t pid;
    int status;


    if ((pid = fork()) < 0) 
    {
        debug_error("fork error");
        exit(-1);
    } 
    else if (pid > 0) //父进程
    { /* parent */
        parent();
        wait(&status);//等待子进程结束

    }
    else 
    { /* child */
        usleep(200);
        child();
    }

    exit(0);
}

