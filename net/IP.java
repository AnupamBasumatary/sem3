import java.util.Scanner;
class IP
{
	
	char check(int a[])
	{	
		if(a[0]==0)
			return 'A';
		else if(a[1]==0)
				return 'B';
			 else if(a[2]==0)
			 		return 'C';
			 		else if(ar[3]==0)
							return 'D';
						else
							return 'E';
	}

	public static void main(String args)
	{
		Scanner sc=new Scanner(System.in);
		String s=sc.next();
		int n=s.length;
		int ar[]=new int[3];
		int k=0;		
		for(int i=0;i<n;i++)
		{
			if(s[i]=='.')
				ar[k++]=i;
		}
		String s1[]=new String[4];
		s1[0]=s.substring(0,ar[0]);
		s1[1]=s.substring(ar[0]+1,ar[1]);
		s1[2]=s.substring(ar[1]+1,ar[2]);
		s1[3]=s.substring(ar[2]+1,s.length);

		int a[]=new int[4];
		String ip[]=new String[4];
		for(int i=0;i<4;i++)
			a[i]=s1[i].Integer.parseInt();
		for(int i=0;i<4;i++)
		 	ip[i]=Integer.toBinaryString(a[i]);
		System.out.println("IP is: "+ip[0]+"."ip[1]+"."+ip[2]+"."+ip[3]);

		int arr[][]=new int[4][8];
		
		for(int i=0;i<4;i++)
			for(int j=0;j<8;j++)
			{			
				arr[3-i][7-j]=ip[3-i]%10;
				ip[3-i]/=10;
			}
		int ipf[]=new int[32];
		k=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<8;j++)			
				ipf[k++]=arr[i][j];	
		System.out.println("class is: "+ check(ipf));		
	}
}
