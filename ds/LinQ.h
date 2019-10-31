#include <iostream>
using namespace std;
class Node
{	
public:
	int info;
	Node* next;
};
class LL{

		Node *f,*r;
	public:
		LL()
		{
			f=r=NULL;			
		}
		void enq(int x)
		{
			Node *t=new Node();
			t->info=x;
			t->next=NULL;
			if(f==NULL)
				f=r=t;
			else
			{
				r->next=t;
				r=t;
			}
		}
		int deq()
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
			return x;
		}
		void show()
		{
			Node *t=f;
			if(f==NULL)
			{
				cout<<"\nNothing to display\n";
				return;
			}
			while(t!=NULL)
			{
				cout<<t->info<<"\n";
				t=t->next;
			}
		}
};