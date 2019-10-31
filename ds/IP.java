import java.util.Scanner;
class IP
{
	
	char check()
	{

	}


	public static void main(String args)
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int n=s.length;
		int ar[3];
		int k=0;		
		for(int i=0;i<n;i++)
		{
			if(s[i]=='.')
				ar[k++]=i;
		}
		String s1[4];
		s1[0]=s.substring(0,ar[0]);
		s1[1]=s.substring(ar[0]+1,ar[1]);
		s1[2]=s.substring(ar[1]+1,ar[2]);
		s1[3]=s.substring(ar[2]+1,s.length);

		int a[4];
		String ip[4];
		for(int i=0;i<4;i++)
			a[i]=s1[i].Integer.parseInt();
		for(int i=0;i<4;i++)
		 	ip[i]=Integer.toBinaryString(a[i]);
		System.out.println("IP is: "+ip[0]+"."ip[1]+"."+ip[2]+"."+ip[3]);
		
	}
}