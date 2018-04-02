#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>


sem_t common;

int count=0,gcount=0;

int flag=0;
void *game()
{
    sem_wait(&common);
    count++;
    printf("player %d entering the ground\n",count);
    sleep(3);
    if(count!=3)
    {
        printf("match can't be started ");
        printf("Need %d more player for game\n",(3-count));
        sleep(3);
        flag=0;
    }
    else
    flag=1;

