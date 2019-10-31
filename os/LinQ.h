#include <iostream>
using namespace std;
class Node
{	
public:
	int info;
	Node* next;
	int i;
};
class LL{

		Node *f,*r;
	public:
		LL()
		{
			f=r=NULL;
			i=0;			
		}
		void enq()
		{
			if(i==3)
				deq();
			else
			{
				cout<<"\nEnter ur element: ";
				Node *t=new Node();
				cin>>t->info;
				t->next=NULL;
				if(f==NULL)
					f=r=t;
				else
				{
					r->next=t;
					r=t;
				}
				i++;
			}
		}
		void deq()
		{
			Node *t;
			if(f==NULL)
				throw "\nUnderflow Ocuurs!";
			t=f;
			f=f->next;
			if(f==NULL)
				r=NULL;
			int x=t->info;
			delete t;
			i--;
			enq();
		}

		void traverse()
		{
			if(f==NULL)
				enq();
			while(f!=NULL)
			{
				
			}
		}
};