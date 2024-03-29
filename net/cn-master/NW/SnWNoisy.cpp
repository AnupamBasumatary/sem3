#include <iostream>
#include <cstdlib>

using namespace std;

int r=1;
int receiver(int seq){



    int x=rand()%10;

    if(x<5){
        cout<<"\n\tReceived frame with sequence no :: "<<seq;
        r=1-r;
        cout<<"\n\tACKNOWLEDGMENT "<<r<<" sending";
    }

    else if(x>5&&x<8){
        cout<<"\n\tFrame lost!!";
        cout<<"\n\tTimeout!!!";
    }

    else{
    	cout<<"\n\tAcknowledgement lost!!";
        cout<<"\n\tTimeout!!!";
    }
    return r;
}


void sender(){
    int n;
    cout<<"\t\t-----Sender------\n";
    
    cout<<"\nEnter the number of frames :: ";
    cin>>n;

    int arr[n];

    for(int i=0;i<n;i++){
        if(i%2==0)
            arr[i]=1;
        else
            arr[i]=0;
    }

    for(int i=0;i<n;i++){

     	cout<<"\n\nSending frame with sequence number::"<<arr[i];
         int ack=receiver(arr[i]);

        while(ack==arr[i]){

     		cout<<"\n\nResending frame with sequence number "<<arr[i];
     		ack=receiver(arr[i]);
	}
    }
   

	cout<<"\n\t----------- TRANSMISSION COMPLETE ---------------";
}
int main(){
    sender();

    return 0;
}
