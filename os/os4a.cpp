#include<stdio.h>
#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
using namespace std;
int main()
{
	int pid = fork();
	if(pid < 0)
	{
		cout<<"Fork failed!";
		return -1;
	}
	cout<<"\nHello\n";
}
