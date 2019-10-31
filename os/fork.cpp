#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[])
{
	int pid;
	pid=fork();
	if(pid<0)
	{
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if(pid==0)
	{
		
		cout<<getpid()<<"\n";
		cout<<getppid()<<"\n";
		cout<<pid<<"\n";
		execlp("/bin/ls","/s",NULL);
	}
	else
	{
		wait(NULL);
		cout<<getpid()<<"\n";
		cout<<getppid()<<"\n";
		cout<<pid<<"\n";
		printf("Child Complete");
		exit(0);
	}
	return 0;
}
