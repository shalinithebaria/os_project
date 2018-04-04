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
     if(flag==1)
    {
        //crtical section
        gcount++;
        printf("\n\n---------------------------------------\n\n");
        printf("yeah!! 3 players are in....\n");
        printf("match %d\n",gcount);
        printf("lets start the game\n");
         printf("\n\n---------------------------------------\n\n");
        sleep(6);
        printf("server is occupied, as match is going on, no one can now enter \n");
         printf("\n\n---------------------------------------\n\n");
        sleep(4);
        printf("now match %d is over, other players can enter now \n",gcount);
        printf("\n\n---------------------------------------\n\n");
        

        count=0;

    }
     sem_post(&common);

}
int main()
{
    printf("Total 3 players are needed to start a game \n");
    sleep(3);
    pthread_t p[6];
    sem_init(&common,0,3);
    for(int  i=0;i<6;i++)
{
    pthread_create(&p[i],NULL,game,NULL);
    pthread_join(p[i],NULL);
}

}

