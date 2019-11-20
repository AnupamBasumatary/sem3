#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "StackLinked.h"
using namespace std;
class Postfix
{
	public :
	Stack<float> opndstk;
	float oper(float x,float y,char ch)
	{
		switch(ch)
		{
			case '+' :return (x+y);
			case '-' :return (x-y);
			case '*' :return (x*y);
			case '/' :return (x/y);
			case '$' :return pow(x,y);
			case '^' :return pow(x,y);
			default : throw x;
		}
	}
	bool pred(char op1,char op2)
	{
		if(op1=='(')
			return false;
		if(op2=='(')
			return false;
		if((op1=='$' && op2=='$') || (op1=='^' && op2=='^'))
			return false;
		if(priority(op1)>=priority(op2))
			return true;
		else
			return false;
	}
	int priority(char op)
	{
		switch(op)
		{
			case '$' : return 3;
			case '^' : return 3;
			case '*' : return 2;
			case '/' : return 2;
			case '%' : return 2; 
			case '+' : return 1;
			case '-' : return 1;
			default : return 0;
		}
	}
	string infixconversion(string s)
	{
		string s1="";
		Stack<char> oprstk;
		for(int i=0;i<s.length();i++)
		{
			char ch=s.at(i);
			if(ch>='0' && ch<='9')
				s1=s1+ch;
			else if(ch=='(')
				oprstk.push(ch);
			else if(ch==')')
			{
				char c=oprstk.pop();
				while(!oprstk.empty() && c!='(')
				{
					s1=s1+c;
					c=oprstk.pop();
				}
			}
			else
			{
				
				while(!oprstk.empty() && pred(oprstk.first->info,ch))
				{
					char c;
					c=oprstk.pop();
					s1=s1+c;
				}
				oprstk.push(ch);
			}
		}
		while(!oprstk.empty())
			s1=s1+oprstk.pop();
		return s1;
	}
	float postfixevaluation(string s)
	{
		for(int i=0;i<s.length();i++)
		{
			char ch=s.at(i);
			if(ch>='0' && ch<='9' )
				opndstk.push(ch-'0');
			else
			{
				float opnd2=opndstk.pop();
				float opnd1=opndstk.pop();
				float value=oper(opnd1,opnd2,ch);
				opndstk.push(value);
			}
		}
		float f=opndstk.pop();
		if(!opndstk.empty())
			throw f;
		return f;
	}
};
int main()
{
	fstream file;
	Postfix ob1;
	int ch;
		file.open("t.txt",ios::in); //open a file to perform read operation using file object
		if (file.is_open()){   //checking whether the file is open
			string s;
			while(getline(file, s)){ //read data from file object and put it into string.
				string s1=ob1.infixconversion(s); //print the data of the string
				float result=ob1.postfixevaluation(s1);
				cout<<result<<"\n";
			}
			file.close(); //close the file object.
		}
}
