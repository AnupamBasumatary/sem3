#include <iostream>
#include</usr/include/sys/sysinfo.h>
using nampespace std;
void CPUprint()
{
    cout<<"CPU Type and Model:";
    System("grep'model name'/proc/cpuinfo|awk '{print $4,45,$6,$7,$8}'");       //$0 for all
    cout<<"\nKernel Version:";
    System("cat /proc/sys/nKernel/osrelease");
    cout<<"CPU Times:";
    System("cat /proc/uptime|awk '{print $1 \t $2}'");  //$1 for on amd $2 for idle
}
void meminfo()
{
    struct sysinfo sinfo;
    if(sysinfo(&sinfo)<0)
    {
        cout<<"Error in finding info";
        exit(1);
    }
    cout<<"\nAmount of memory configured into system:"<<sinfo.totalram/1024<<"KB";
    cout<<"Amount of memory currently available"<<sinfo.freeram/1024<<"KB";
}
int main()
{
    CPUprint();
    meminfo();
    return 0;
}