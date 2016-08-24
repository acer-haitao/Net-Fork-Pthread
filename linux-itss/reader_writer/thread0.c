#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

extern pthread_rwlock_t rwlock;


void print0(size_t count)
{
    int i;

    for (i = 0; i < count; i++)
    {
        fprintf(stderr, "0");
    }
    fprintf(stderr, "\n");
}
/***********************************************************************
 * 读写锁适用于：对数据结构读次数多于写操作的场合-->因为读模式锁定时
 * 可以共享(多个线程可以同时占用读模式)，但写模式锁定时只能某一个线程占
 * 用
 ***********************************************************************/ 
void *thread0(void *cmd)
{
    while(1)
    {
        pthread_rwlock_rdlock(&rwlock);
        print0(100);
        pthread_rwlock_unlock(&rwlock);
    }
	/* 读写锁的三种状态：
	 * 1 写加锁-->解锁之前，所有试图加锁的线程则会被堵塞；
	 * 2 读加锁-->所有以读模式加锁的线程都可获取访问权，但是以写的模式加锁的线程被堵塞
	 * 3 在读模式锁状态时，如果另外线程以写模式加锁，读写锁通常堵塞随后的读模式锁请求
	 *   避免读模式长期占用，而写模式锁请求则长期堵塞*/
    return NULL;
}

