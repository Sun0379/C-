#include <stdio.h>
#include <pthread.h>

void thread1(void)
{
    int i;
    for (i=0;i<3;i++)
    {
        //printf("thread1 id = %lu\n",pthread_self());
        printf("123");

    }
}
void thread2(void)
{
    int i;
    for (i=0;i<3;i++)
    {
        printf("456");
    }
}
int main(void)
{
    //sizeof  4;x86_64=8
    pthread_t id1;
    pthread_t id2;
    int i,ret;
    ret = pthread_create(&id1,NULL,(void *)thread1,NULL);
    if(ret!=0)
    {
        printf("Create pthread error!\n");
        exit(1);
    }
    ret = pthread_create(&id2,NULL,(void *)thread2,NULL);
    if(ret!=0)
    {
        printf("Create pthread error!\n");
        exit(1);
    }
    for (i=0;i<3;i++)
    {
        //注意'\n'的输出
        printf("7890\n");
    }
    pthread_join(id2,NULL);
    pthread_join(id1,NULL);
    return 0;

}
