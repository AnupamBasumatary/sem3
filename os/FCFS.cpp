#include<iostream>
using namespace std;
class FcfsProcess
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
		fcfs();
	}
	
	void fcfs()
	{
		int t;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4-i-1;j++)
			{
				if(AT[j]>AT[j+1])
				{
					t=AT[j];
					AT[j]=AT[j+1];
					AT[j+1]=t;
					
					t=BT[j];
					BT[j]=BT[j+1];
					BT[j+1]=t;
					
					t=P[j];
					P[j]=P[j+1];
					P[j+1]=t;
					
				}
			}
		}
		
		for(int i=0;i<4;i++)
			cout<<" "<<AT[i]<<" "<<BT[i]<<" "<<P[i];
		
		
		
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
		cout<<"\nP  |  WT  |  TaT\n";
		for(i=0;i<4;i++)
			cout<<P[i]<<" |  "<<WT[i]<<"   |  "<<TAT[i]<<"\n";
			
	}	
};

int main()
{
	cout<<"enter the data:\n";
	FcfsProcess f;
	f.inp();
	f.disp();		
	return 0;
}






