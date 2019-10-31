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
int* XOR(int* b1,int* b2)
{
	int* c= new int[8];
	for(int i=0;i<8;i++)
		{
			if(b1[i]==b2[i])
				*(c+i)=0;
			else 
				*(c+i)=1;	
		}
	return c;
}
int main(int ars,char *args[])
{
	float dec1,dec2;
	int *b1,*b2,*b3,*b4,*b5,*b6;
	cout<<"Enter a no.:";
	cin>>dec1;
	int a;
	a=int(dec1);
	b1=dtb1(a);
	b2=dtb2(dec1-a);
	cout<<"\nEnter second number:";
	cin>>dec2;
	a=int(dec2);
	b3=dtb1(a);
	b4=dtb2(dec2-a);
	b5=XOR(b1,b3);
	b6=XOR(b2,b4);
	for(int i=0;i<8;i++)
		cout<<*(b5+i);
	cout<<" . ";
	for(int i=0;i<8;i++)
		cout<<*(b6+i);

}