#include<iostream>
#include<fcntl.h>
using namespace std;
int main()
{
	char sfile[30], tfile[30], buf[1000];
	int sd,td,n;
	cout<<"Enter sourcefile: ";
	cin>>sfile;
	cout<<"Enter target file: ";
	cin>>tfile;
	if((sd = open(sfile, O_RDONLY)) < 0)
	{
		cout<<"Error";
		exit(1);
	}
	if((td = open(tfile, O_CREATE /  O_WRONLY, 0666)) < 0)
	{
		cout<<"Error creating file";
		close(sd);
		exit(2);
	}
	while((n = read(sd, buf, sizeof(buf)) > 0)
		write(td, buf, n);
	close(sd);
	close(td);
	cout<<"File Copied!";
	return 0;
}
		
