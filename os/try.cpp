#include<iostream>
using namespace std;
class FCFS
{
	private:
		int BT[4],AT[4],P[4],WT[4],W[5],TAT[4];
	public:	
	void inp()
	{
		for(int i=0;i<4;i++)
		{
		
		cout<<"\nEnter process name: ";
		cin>>P[i];
		cout<<"\nEnter the burst time: ";
		cin>>BT[i];
		cout<<"\nEnter Arrival Time: ";
		cin>>AT[i];		
		}
		calc();
	}
	
	void calc()
	{
		int t=AT[0];
		for(int i=0;i<4;i++)
		{
			for(int j=i+1;j<4;j++)
			{
				if(AT[i]>AT[j])
				{
					int t=AT[i];
					AT[j]=AT[j];
					AT[j]=t;
					
					t=BT[i];
					BT[i]=BT[j];
					BT[j]=t;
				}
			}
		}
		W[0]=AT[0];
		for(int i=1;i<5;i++)
		{
			W[i]=W[i-1]+BT[i-1];
		}
		for(int i=0;i<4;i++)
		{
			WT[i]=W[i]-AT[i];
		}
		for(int i=0;i<4;i++)
		{
			TAT[i]=BT[i]+WT[i];
		}
	}
	void disp()
	{	
		
		int i,k;
		cout<<"Gnatt Chart: \n";
		for(i=0;i<4;i++)
		{
			cout<<W[i]<<" ";
			if(AT[i]>W[i])
			{
				k=AT[i]-W[i];	
	
				for(int j=i;j<5;j++)
					W[j]+=k;
				cout<<W[i]<<" ";
				WT[i]=0;
				TAT[i]=WT[i]+BT[i];
			}
			cout<<P[i]<<" ";
		}
		cout<<W[i];
		cout<<"\nWT  |  TaT\n";
		for(i=0;i<4;i++)
			cout<<WT[i]<<"   |  "<<TAT[i]<<"\n";
			
	}	
};

int main()
{
	cout<<"enter the data:\n";
	FCFS f;
	f.inp();
	f.disp();		
	return 0;
}






