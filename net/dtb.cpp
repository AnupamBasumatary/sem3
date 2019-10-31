#include<iostream>
using namespace std;

int* dtb1(int a)
{
	int i=7;
	int *b=new int[8];
	while(i)
	{
		*(b+i)=(a%2);
		a=a/2;
		i--;
	}
	return b;
}
int* dtb2(float a)
{
	int i=0;
	int *b=new int[8];
	while(i<8)
	{
			a*=2;
			*(b+i)=int(a);
			a=a-int(a);
			i++;
	}
	return b;
}
int main(int ars,char *args[])
{
	float dec;
	int *b1,*b2;
	cout<<"Enter a no.:\n";
	cin>>dec;
	int a;
	a=int(dec);
	b1=dtb1(a);
	b2=dtb2(dec-a);
	for(int j=0;j<8;j++)
		cout<<*(b1+j);
	cout<<".";
	for(int j=0;j<8;j++)
		cout<<*(b2+j);
}