#include<iostream>
#include</usr/include/sys/sysinfo.h>
using namespace std;

void cpuinfoprint()
{
	cout<<"CPU type & model: ";
	System("grep 'model name' /proc/cpuinfo | awk '{print $4,$5,$6,$7,$8}'");
	
	cout<<"\nKernel version: ";
	System("cat /proc/sys/kernel/osrelease");
	
	cout<<"\nCPU times: ";
	System("cat /proc/uptime | awk '{print $1\t$2}'");
}

void memoryinfo()
{
	struct sysinfo sinp;
	if(sysinfo(&sinfo) < 0)
	{
		cout<<"\nError in finding information.";
		exit(1);
	}
	cout<<"\nAmt of memory configured into system: "<<sinfo.totalram/1024<<"kB";
	cout<<"\nAmt of memory available: "<<sinfo.freeram/1024<<"kB";
}

int main()
{
	cpuinfoprint();
	memoryinfo();
	return 0;
}
		
