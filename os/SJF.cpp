#include<iostream>
using namespace std;
class SJF
{
	private:
		int BT[4],AT[4],P[4],B[4],WT[4],W[5],TAT[4];
	public:	
	void inp()
	{
		for(int i=0;i<4;i++)
		{
		
		cout<<"\nEnter process name: ";
		cin>>P[i];
		cout<<"\nEnter the burst time: ";
		cin>>BT[i];
		AT[i]=0;
		B[i]=BT[i];		
		}
		calc();
	}
	
	void calc()
	{
		W[0]=AT[0];
		int t=-1;
		for(int i=0;i<4;i++)
		{	
			for(int j=i+1;j<4;j++)
			{	
				if(BT[i]>=BT[j])
				{
					t=BT[i];
					BT[i]=BT[j];
					BT[j]=t;
					t=P[i];
					P[i]=P[j];
					P[j]=t;
					t=AT[i];
					AT[i]=AT[j];
					AT[j]=t;			
					
				}
				
			}	
		}
		
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
		for(int i=0;i<4;i++)
		{
			cout<<AT[i]<<" ";
			cout<<BT[i]<<" ";
			cout<<P[i]<<" ";
		}
		
	}
	void disp()
	{	
		cout<<"\nWT  |  TaT\n";
		for(int i=0;i<4;i++)
			cout<<WT[i]<<"   |  "<<TAT[i]<<"\n";
		cout<<"Gnatt Chart: \n";
		for(int i=0;i<5;i++)
			cout<<W[i]<<" ";
		cout<<"\n";
		for(int i=0;i<4;i++)
			cout<<P[i]<<" ";	
	}	
};

int main()
{
	cout<<"enter the data:\n";
	SJF f;
	f.inp();
	f.disp();		
	return 0;
}






