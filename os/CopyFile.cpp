#include<iostream>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
	using namespace std;
int main()
{
	char sfile[30],tfile[30],buf[1000];
	int sd,td,n;
	cout<<"\nEnter source file:";
    cin>>sfile;
    cout<<"\nEnter target file:";
    cin>>tfile;
    if((sd=open(sfile,O_RDONLY))<0)
    {
        cout<<"\nERROR";
        exit(1);
    }
    if((td=open(tfile,O_CREAT|O_WRONLY,0666))<0)
    {
        cout<<"Error creating file";
        close(sd);
        exit(2);
    }
    while((n=read(sd,buf,sizeof(buf)))>0)
        write(td,buf,n);
    close(sd);
    close(td);
    cout<<"\nFile Copied";
    return 0;
}
	
