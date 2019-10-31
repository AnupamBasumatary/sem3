#include<stdio.h>
#include<stdlib.h>
int in=0,out=0;
int sm[5];

void producer(int prod)
{
	if((in+1)%3!=out)
	{
		sm[in]=prod;
		in=(in+1)%5;
	}
	else
	printf("\nBuffer is full");
}
int consumer()
{
	int cons;
	if(in!=out)
	{
		cons=sm[out];
		out=(out+1)%5;
		return cons;
	}
	else
	{
		printf("\nBuffer Empty");
		return -9999;
	}
}
int main()
{
	int con,cons,prod;
	do
	{
		int i=rand()%2;
		if(i==0)
		{
			printf("\nEnter the input");
			scanf("%d",&prod);
			producer(prod);
		}
		else
		{
				cons=consumer();
				printf("\nConsume output:%d", cons);
		}
	}while(true);
	return 0;
}
