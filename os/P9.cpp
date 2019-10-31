#include <iostream>
using namespace std;

	int main()
	{
	  	int n;int n1;
	  	cout<<"Enter No. of process\n";
	  	cin>>n;
	  	int ar[n];
	  	cout<<"Enter size of process";
	  	for(int i=0;i<n;i++)
	   		cin>>ar[i];
	  	cout<<"Enter No. of chamber\n";
	  	cin>>n1;		
	  	int ar2[n1],check[n1],ar3[n1];
	  	cout<<"Enter size of chamber";
	  	for(int i=0;i<n1;i++)
	  		cin>>ar2[i];
	  	for(int i=0;i<n1;i++)
	  	{
	  		check[i]=0;
	  		ar3[i]=0;
	  	}		
	  	int ch;
	  	do
	  	{
		  	cout<<"\nOption\n1 for FirstFit \n2 for BestFit \n3 for WorstFit\n4.exit\n";
		  	cin>>ch;
		  	
		  	
		  	switch(ch)
		  	{
				case 1:	for(int i=0;i<n1;i++)
					  	{
					  		check[i]=0;
					  		ar3[i]=0;
					  	}
						{
				        for(int j=0;j<n;j++)
					    {	
						for(int i=0;i<n1;i++)
						   {
							    if(check[i]==1)
							    continue;
							    else if(ar[j]<ar2[i])
						        {   
						                
						            ar3[i]=j;
							        check[i]=1;
							        break;
							    }
							    else 
							    continue;
						    }						
					    }}
					  break;
				case 2:	for(int i=0;i<n1;i++)
					  	{
					  		check[i]=0;
					  		ar3[i]=0;
					  	}
						{int min=999;int k1=-1;
				       for(int j=0;j<n;j++)
					  {	
						for(int i=0;i<n1;i++)
						   {
							    if(check[i]==1)
							    continue;
							    else if(ar[j]<=ar2[i])
							    {
							        int min1=ar2[i]-ar[j];
							        if(min1<=min)
							        {
							            min=min1;
							            k1=i;
								    }						
					            }
					            else
					            continue;
					      }
					        if(k1!=-1)
					        {ar3[k1]=j;	
							check[k1]=1;	    
							}
							min=999;k1=-1;
					  }}
					  break;
				case 3:for(int i=0;i<n1;i++)
					  	{
					  		check[i]=0;
					  		ar3[i]=0;
					  	}
						{
						int max=ar[0];int k2=-1;
				       for(int j=0;j<n;j++)
					  	{	
						for(int i=0;i<n1;i++)
						   {
							    if(check[i]==1)
							    continue;
							    else if(ar[j]<=ar2[i])
							    {
							        if(max<=ar2[i])
							        {
							            max=ar2[i];
							            k2=i;
								    }						
					            }
					            else
					            continue;
					      }	  	  
					      if(k2!=-1)
					        {ar3[k2]=j;	
							check[k2]=1;	    
							}
							max=ar[0];k2=-1;
					  }}
					  break;
					  case 4: return 0;
					  default: cout<"\nEnter correct choice:\n";
				  	  
			}
			cout<<"\nProcess Size:\n";
			for(int i=0;i<n;i++)
				cout<<ar[i]<<"\t";
			cout<<"\nChamber size\n:";
			for(int i=0;i<n1;i++)
				cout<<ar2[i]<<"\t";
			for(int i=0;i<n1;i++)
			    {
			    if(check[i]==1)
			    cout<<"P"<<ar3[i]+1<<"\t";
			    else
			    cout<<"null";
			    }
	   }while(true);
	   } 
	
		
					
		
