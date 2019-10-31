#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <pthread.h>
using namespace std;
int sum=0;
void *runner(void *param);
int main(int argc,char* arg[])
{
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2)
	{
		fprintf(stderr,"usage: a.out <integer value\n");
		return -1;
	} 
	if(atoi((char *)arg[1])<0)
	{
		fprintf(stderr,"%d must be >=0 \n",atoi((char *)arg[1]));
		return -1;
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,arg[1]);
	pthread_join(tid,NULL);
	printf("sum=%d",sum);
}
void *runner(void *param)
{
	int up=atoi((char *)param);
	for(int i=1;i<=up;i++)
		sum+=i;
	pthread_exit(0);
}