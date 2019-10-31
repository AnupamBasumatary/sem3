#include<iostream>
#include<cmath>
#include<cstdlib>

using namespace std;



int main() {

	int n,k=0;

	cout<<"\n\nSender Side\n\n";

	cout<<"Enter no. of bits in your data: ";
	cin>>n;

	int r=1;

	while(true){
		if(n+r+1<=(int)pow(2,r)){
			break;
			
		}
		else {
			r++;
		}
	}
	int check[r];
	int m=n+r;

	int a[n],data[m];
 
	for(int i=0;i<r;++i){
		check[i]=0;
	}

	for(int i=0;i<m;++i){
		data[i]=0;
	}

	for(int i=0;i<n;i++)
		cin>>a[i];
	k=0;
	int p=0;
	for(int i=0;i<m;i++) {
		if ((i+1)==pow(2,p)) {
			p++;
			continue;
		}
		else
		data[i]=a[k++];
	} 

	
int ctr;
for(int i=0;i<m;i++) {

	if(data[i]==1) {

	ctr=i+1;
		for(p=r-1;p>=0;p--)
		{
			if(ctr>=pow(2,p))
			{
				ctr-=pow(2,p);
				(check[p])++;
			}
		}

	}
}
p=0;
k=0;
	while(k<m) 
	{

		if(k+1==pow(2,p)){ 

			if(check[p]%2==0)
				data[k]=1;
			else
				data[k]=0;

			k++;
			p++;
		}
		else
			k++;
	}

cout<<"Codeword Using Odd parity: ";
for (int i=0;i<m;++i){
		cout<<data[i];
}

int copy[m];
for (int i=0;i<m;++i) {

	copy[i]=data[i];
}

cout<<"\nData Sent: ";
for (int i=0;i<m;++i){
	cout<<copy[i];
}

int ran = (rand()%m);
    if(copy[ran]==0){
        copy[ran]=1;

    }
    else{
        copy[ran]=0;
    }
    

    cout<<"\n\nReciever Side\n\n";

 cout<<"\nData Received: ";
 for (int i=0;i<m;++i){ 
	cout<<copy[i];	
 }

cout<<"\n\tChecking..";

int errBit=-1;

for(int i=0; i<m; ++i) {
	if(data[i] != copy[i]) {
		errBit = i+1;
	}
}

if(errBit != -1) {

cout<<"\nError bit: "<<errBit<<endl;

if(copy[errBit-1]==1) {
		copy[errBit-1]=0;
	}
	else {
		copy[errBit-1]=1;
	} 
	
	
	cout<<"\nData after correction: ";
	for (int i=0;i<m;++i){ 
	cout<<copy[i];
 	}
}

else {
	cout<<"Received Data is correct";
	cout<<endl;
}

 
}
