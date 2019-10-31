import java.util.Scanner;
class Matrix
{
	protected int ar[],m,n;
	
	public int getm()
	{
		return m;
	}
	public int getn()
	{
		return n;
	}	
	public void set(int i,int j){
		return;
	}
	public void sete(int i,int j){
		return;
	}
	public int get(int i,int j){
		return 0;
	}
}
class SimpleMatrix extends Matrix{

	public SimpleMatrix()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of the m X n matrix");
		m=sc.nextInt();
		n=sc.nextInt();
		ar=new int[m*n];
	}
	public void set(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a["+i+"]["+j+"]: ");
		ar[i*n+j]=sc.nextInt();	
	}
	public void sete(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter a["+i+"]["+j+"]: ");
		ar[i*n+j]=sc.nextInt();
	}


	public int get(int i,int j)
	{
		return ar[i*n+j];
	}
}

class dMatrix extends Matrix{

public dMatrix()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of the matrix n");
		n=sc.nextInt();
		m=n;
		ar=new int[m];
	}
	public void set(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(i==j) 
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[i]=sc.nextInt();
		}
	}
	public void sete(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(i!=j)
			System.out.println("for diagonal matrix it should be a zero element!");
		else 
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[i]=sc.nextInt();
		}
	}
	public int get(int i,int j)
	{
	if(i!=j)
		return 0;
	else 
		return ar[i];
	}
}

class lMatrix extends Matrix
{
	public lMatrix()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of the matrix n");
		n=sc.nextInt();
		m=n;
		ar=new int[n*(n+1)/2];
	}
	public void set(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(j<=i)
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[i*(i+1)/2 + j]=sc.nextInt();
		}
	}
	public void sete(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(j>i)
			System.out.println("for lower triangular matrix these elements must be 0");
		else
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[i*(i+1)/2 + j]=sc.nextInt();
		}
	}
	public int get(int i,int j)
	{
		if(j>i)
			return 0;
		else
			return ar[i*(i+1)/2 + j];
	}
}

class uMatrix extends Matrix{

	public uMatrix()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of the matrix n");
		n=sc.nextInt();
		m=n;
		ar=new int[n*(n+1)/2];
	}
	public void set(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(j>=i)
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[n*(n+1)/2 - (n-i)*(n-i+1)/2 + j-i]= sc.nextInt();
		}
	}
	public void sete(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(j<i)
			System.out.println("for upper triangular matrix these elements must be 0");
		else
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[n*(n+1)/2 - (n-i)*(n-i+1)/2 + j-i]= sc.nextInt();
		}
	}
	public int get(int i,int j)
	{
		if(j<i)
			return 0;
		else
			return ar[(i*(2*n-i-1)+2*j)/2];
	} 
}

class trdMatrix extends Matrix{

	public trdMatrix()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of the matrix n");
		n=sc.nextInt();
		m=n;
		ar=new int[n+ 2*(n-1)];
	}
	public void set(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		switch(i-j)
		{
			case 1:		System.out.println("enter a["+i+"]["+j+"]: ");
						ar[i-1]=sc.nextInt();
						break;
			case 0:		System.out.println("enter a["+i+"]["+j+"]: ");
						ar[n+i-1]=sc.nextInt();
						break;
			case -1:	System.out.println("enter a["+i+"]["+j+"]: ");
						ar[(2*n) + (i-1)]=sc.nextInt();
						break;
		}
	}
	public void sete(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		switch(i-j)
		{
			case 1:		System.out.println("enter a["+i+"]["+j+"]: ");
						ar[i-1]=sc.nextInt();
						break;
			case 0:		System.out.println("enter a["+i+"]["+j+"]: ");
						ar[n+i-1]=sc.nextInt();
						break;
			case -1:	System.out.println("enter a["+i+"]["+j+"]: ");
						ar[(2*n) + (i-1)]=sc.nextInt();
						break;
			default:	System.out.println("this element must be 0");
		}
	}
	public int get(int i,int j)
	{
	
		switch(i-j)
		{
			case 1:		return ar[i-1];
			case 0:		return ar[n+i-1];
			case -1:	return ar[(2*n) + (i-1)];
			default:	return 0;
		}
	}  
}

class sMatrix extends Matrix{
	public sMatrix()
	{
		Scanner sc= new Scanner(System.in);
		System.out.println("Enter the size of the matrix n");
		n=sc.nextInt();
		m=n;
		ar=new int[(n*(n+1))/2];
	}
	public void set(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(j<=i)
		{    
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[(i*(i+1))/2 + j]=sc.nextInt();
		}
	}
	public void sete(int i,int j)
	{
		Scanner sc=new Scanner(System.in);
		if(j<=i)
		{    
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[(i*(i+1))/2 + j]=sc.nextInt();
		}
		else
		{
			System.out.println("enter a["+i+"]["+j+"]: ");
			ar[(j*(j+1))/2 + i]=sc.nextInt();
		}
	}
	public int get(int i,int j)
	{
		if(j<=i)
			return ar[i*(i+1)/2 + j];
		else
			return ar[j*(j+1)/2 + i];
	}  
}

class P1
{
	public static void main(String[] args)
	{	
		Matrix m=new Matrix();
		int k=0;
		do{
					Scanner sc=new Scanner(System.in);
					int c;
					do
					{		
							System.out.println("\nEnter your choice:\n1.Simple rectangle matrix\n2.Diagonal matrix\n3.Lower traingular matrix\n4.upper triangular matrix\n5.tri-diagonal matrix\n6.symmetric matrix\n7.exit");
							c=sc.nextInt();
							switch(c)
							{
								case 1: 	m=new SimpleMatrix();
											break;
								case 2: 	m=new dMatrix();
											break;
								case 3: 	m=new lMatrix();
											break;
								case 4: 	m=new uMatrix();
											break;
								case 5: 	m=new trdMatrix();
											break;
								case 6: 	m=new sMatrix();
											break;	
								case 7:		System.exit(0);
								default:	System.out.println("\nEnter Correct Choice!");
							}
					}while(c<1 || c>7);

						boolean p=true;
						do
						{
								System.out.println("Enter your choice:\n1.create\n2.edit\n3.show single\n4.display\n5.exit");
								int z=sc.nextInt();
								int a=m.getm();
								int b=m.getn();
								switch(z)
								{
									case 1:		k++;	
												for(int i=0;i<a;i++)
													for(int j=0;j<b;j++)
													{
															m.set(i,j);
													}
												break;

									case 2:		if(k>0)
												{
													System.out.println("enter the i & j for the element to be insert");
													int i=sc.nextInt();
													int j=sc.nextInt();
													if(i>=a || j>=b ||i<0 || j<0)
														System.out.println("i & j are not in the range");
													else 
														m.sete(i,j);
												}
												else
													System.out.println("\nFirst you have to enter input for the matrix then u can edit\n");
												break;
									case 3: 	if(k>0)
												{

													System.out.println("enter the i & j for the element to be insert");
													int i=sc.nextInt();
													int j=sc.nextInt();
													if(i>=a||j>=b ||i<0 || j<0)
														System.out.println("i & j are not in the range");
													else 
														System.out.println("Your element is: "+m.get(i,j));
												}
												else
													System.out.println("First you have to enter input for the matrix then u can see a particular element");
												break;
									case 4:		if(k>0)
												{
														for(int i=0;i<a;i++)
														{
															for(int j=0;j<b;j++)
																System.out.print(m.get(i,j)+" ");
															System.out.println();
														}
												}			
												else
													System.out.println("Enter the input of matrix first");

												break;
									case 5: 	k=0;
												p=false;
												break;
									default: 	System.out.println("\nEnter correct Choice!");
								}
						}while(p);
		}while(true);
	}
}