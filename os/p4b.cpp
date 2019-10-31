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
		cout<<"Executed by Child Process\n";
		cout<<"The pid here is: "<<pid<<endl;	
	}
	else
	{
		cout<<"Executed by parent\n";
		cout<<"pid here is: "<<pid<<endl;
	}
	return 0;
}
