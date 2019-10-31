#include<iostream>
#include<cstdlib>
using namespace std;
class data
{
	int ar[5],n,br[5];

	public:
	void create()
	{
		int c=0;
		cout<<"\nEnter The no.: \n";
		for(int i=0;i<4;i++)
		{
			cin>>ar[i];
			if(ar[i]==1)
				c++;
		}
		if(c%2==1)
			ar[4]=1;
		else
			ar[4]=0;
		cout<<"\nTransmitted word is: \n";
		for(int i=0;i<5;i++)
			cout<<ar[i];
		parity();
	}

	void parity()
	{
		int c=0;
		cout<<"\n";
		for(int i=0;i<5;i++)
		{
			br[i]=rand()%2;
			cout<<br[i];
			if(br[i]==1)
				c++;
		}
		if(c%2==1)
			cout<<"\nParity doesn't matched\n";
		else
			cout<<"\nParity matched\n";
	}
};
int main(int arg,char *args[])
{
	data d;
	int t=0;
	while(1)
	{
		d.create();
		cout<<"\nAgain? type 1 to continue else any other no. to exit:";
		cin>>t;
		if(t!=1)
			return 0;
	}
	return 0;
}