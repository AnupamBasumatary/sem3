#include<iostream>
#include<stdlib.h>
	using namespace std;
class Operations
{
	public:
		void bubble_sort(int a[],int n)
		{  
			bool sw= true;
    			for(int i=0;i<n-1;i++)      
      			{
				
				for(int j=0;j<n-i-1;j++)  
        			{
					if(a[j]>a[j+1])  
					{
						
            				swap(a[j],a[j+1]);
					}
				}
				display(a,n);
			}
		}
		void insertion_sort(int a[],int n)
		{  
			int i,key,j;  
    			for (i=1;i<n;i++) 
    			{  
        			key=a[i];  
        			j=i-1;  
    	   			while(j>=0 && a[j]>key) 
        			{  
            				a[j+1]=a[j];  
            				j=j-1;  
        			}  
        			a[j+1]=key;  
    			}  
		}
		void selection_sort(int a[],int n)
		{  
			int i,j,min;    
    			for (i = 0; i < n-1; i++)  
   			{   
        			min=i;  
        			for(j=i+1;j<n;j++)  
					if(a[j]<a[min])  
            					min=j;   
      	  			swap(a[min],a[i]);    
			}  
		} 
		int linear_search(int a[],int target,int n)
		{ 
    			for(int i=0;i<n;i++) 
			{
        			if(a[i]==target) 
            				return i; 
    			}
			return -1;
		}
		int binary_search(int a[],int target,int n)
		{
			int low=0,high=n-1;	
			int mid;
			do
			{
				mid=(high+low)/2;
				if(a[mid]==target)
					return mid;
				else if(a[mid]<target) 
            			low=mid+1;  
        		else if(a[mid]>target)
        				high=mid-1; 
    		}while(low<=high);
  			return -1;
		} 	
		void quick_sort(int a[],int lb,int ub)
		{
			if(lb<=ub)
			{
				int pos=partition(a,lb,ub);
				quick_sort(a,lb,pos-1);
				quick_sort(a,pos+1,ub);
			}
		}
		int partition(int x[],int lb,int ub)
		{
			int a=x[lb];
			int up=ub;
			int down=lb;
			while(down<up)
			{
				while(x[down]<=a && down<ub)
					down++;
				while(x[up]>a)
					up--;
				if(down<up)
					swap(x[down],x[up]);
			}
			x[lb]=x[up];
			x[up]=a;
			return up;
		}
		void merge_sort(int x[],int n)
		{
			int size=1;
			int l1,l2,u1,u2;
			int k;
			int *aux;
			aux=new int[n];
			int i,j;
			while(size<n)
			{
				l1=k=0;
				while(l1+size<n)
				{
					l2=l1+size;
					u1=l2-1;
					u2=(l2+size-1<n)?(l2+size-1):n-1;
					for(i=l1,j=l2;i<=u1 && j<=u2;k++)
					{
						if(x[i]<=x[j])
							aux[k]=x[i++];
						else
							aux[k]=x[j++];
					}
					for(;i<=u1;k++)
						aux[k]=x[i++];
					for(;j<=u2;k++)
						aux[k]=x[j++];
					l1=u2+1;
				}
				for(i=l1;k<n;i++)
					aux[k++]=x[i];
				for(i=0;i<n;i++)
					x[i]=aux[i];
				size*=2;
			}
		}
		void display(int a[],int n)
		{
			cout<<"\nThe sorted elements are as follows:\n";
			for(int i=0;i<n;i++)
			{
				cout<<a[i]<<"  ";
			}
		}
};
int main()
{
	int *a;
	int n;
	a=new int[n];
	int opt;
	int target,loc;
	Operations ob;
	do
	{
		cout<<"\nEnter:\n(1)Bubble Sort\n(2)Insertion Sort\n(3)Selection Sort";
		cout<<"\n(4)Quick Sort\n(5)Merge Sort\n(6)Linear Search\n(7)Binary Search\n";
		cout<<"(8)Exit\n------------------------->";
		cin>>opt;
		if(opt>0 && opt<8)
		{
			cout<<"\nKindly enter the no. of terms:";
			cin>>n;
			cout<<"\nKindly enter the elements of the array:\n";
			for(int i=0;i<n;i++)
			{
				cout<<"\nElement "<<(i+1)<<":";
				cin>>a[i];
			}
		}
		if(opt==1)
		{
			ob.bubble_sort(a,n);
			ob.display(a,n);
		}
		else if(opt==2)
		{
			ob.insertion_sort(a,n);
			ob.display(a,n);
		}
		else if(opt==3)
		{
			ob.selection_sort(a,n);
			ob.display(a,n);
		}
		else if(opt==4)
		{
			ob.quick_sort(a,0,n-1);
			ob.display(a,n);
		}
		else if(opt==5)
		{
			ob.merge_sort(a,n);
			ob.display(a,n);
		}
		else if(opt==6)
		{
			cout<<"\nKindly enter the element to be searched:";
			cin>>target;
			loc=ob.linear_search(a,target,n);
			if(loc==-1)
				cout<<"\nSearch Unsuccessful.Element not found.";
			else
				cout<<"\nSearch Successful.Element found at location "<<(loc+1);
		}
		else if(opt==7)
		{
			cout<<"\nKindly enter the element to be searched:";
			cin>>target;
			ob.bubble_sort(a,n);
			ob.display(a,n);
			loc=ob.binary_search(a,target,n);
			if(loc==-1)
				cout<<"\nSearch Unsuccessful.Element not found.";
			else
				cout<<"\nSearch Successful.Element found at location "<<(loc+1);
		}
		else if(opt==8)
			exit(1);
		else
			cout<<"\nInvalid Input";
	}while(1);
	return 0;
}






 







 
