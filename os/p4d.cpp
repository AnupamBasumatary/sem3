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
	if(pid==0)
	{
		cout<<"\nExecuted by child:\n";
		execlp("/bin/pwd","pwd",NULL);
		cout<<"The pid here is: "<<pid<<endl;	
	}
	else
	{
		wait(NULL);
		cout<<"Executed by parent\n";
		execlp("/bin/ls","ls",NULL);
	}
	return 0;
}
