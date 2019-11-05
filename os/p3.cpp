#include <iostream>
#include <fcntl.h>
using namespace std;
int main()
{
    char sfile[30],tfile[30],buf[1000];
    int sd,td,n;
    cout<<"\nEnter Source file:";
    cin>sfile;
    cout<<"\nEnter target file:";
    cin>>tfile;
    if(sd=open(sfile,O_RDONLY)<0)
    {
        cout<<"Error";
        exit(1);
    }
    if(td=open(tfile,O_CREAT/O_WRONLY,0666)<0)
    {
        cout<<"\nError";
        close(sd);
        exit(2);
    }
    while((n=read(sd,buf,sizeof(buf)))>0)
    {
        write(td,buf,n);
    }
    close(sd);
    close(td);
    cout<<"\nFile copied";
    return 0;
}