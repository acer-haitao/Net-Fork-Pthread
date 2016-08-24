#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_cond_t con_var;//条件变量就是共享变量状态发生改变时发出通知
extern pthread_mutex_t lock;//提供对该共享变量访问的互斥，防止多个同时访问
/* 采用条件变量:允许一个线程休眠等待直到接到另一线程通知才去执行某些操作*/

void *thread0(void *dummy)
{
    pthread_mutex_lock(&lock);
	/* 当共享变量没有达到预期值
	 * 线程在等待条变量进入睡眠之前解锁互斥量（让别的线程能够访问该变量)
	 * 当被唤醒时，再次加锁*/
    pthread_cond_wait(&con_var, &lock);
	/* 当收到一个通知前一直处于阻塞状态*/
    pthread_mutex_unlock(&lock);

    printf("thread1 waken up\n");

    return NULL;
}

