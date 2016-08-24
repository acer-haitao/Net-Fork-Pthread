#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_cond_t con_var;
extern pthread_mutex_t lock;


void *thread1(void *dummy)
{
    int code;
    sleep(2); // weait 2s to test

    pthread_mutex_lock(&lock);n
    code = pthread_cond_signal(&con_var);//唤醒至少一条

	/* pthread_cond_broadcast唤醒所有堵塞的线程*/
	/* 发送信号：通知一个或多个处于等待的线程
	 * 当某个共享变量的状态发生改变*/
    if (code)
    {
        perror("signal");
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

