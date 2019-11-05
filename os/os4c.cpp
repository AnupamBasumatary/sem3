#include<stdio.h>
#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int main()
{
	int pid;
	pid = fork();
	if(pid < 0)
	{
		cout<<"Fork failed!";
		return -1;
	}
	else if (pid == 0)
	{
		cout<<pid<<endl;
		cout<<getpid()<<endl;
		cout<<getppid()<<endl;
		execlp("/bin/ls", "ls", NULL);		
	}
	else
	{
		wait(NULL);
		cout<<"Child complete\n";
		cout<<"Pid: "<<pid<<endl;
		cout<<getpid()<<endl;
		cout<<getppid()<<endl;
		execlp("/bin/pwd", "pwd", NULL);
		return 0;
	}
}

