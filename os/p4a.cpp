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
	cout<<"Pid is: "<<pid;
	return 0;
}
