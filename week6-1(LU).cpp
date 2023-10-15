#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i,j,n,k;
	cin>>n;
	double A[n][n],sum,kon;
	double L[n][n],U[n][n+1],B[n],Y[n],X[n];
	//A
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j==n)
			{
				cin>>B[i];
			}
			else
			{
				cin>>A[i][j];
			}
			
		}
	}
	//set L
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j>i)
			{
				L[i][j]=0;
			}
			else{
				L[i][j]=-3254;
			}
		}
	}
	
	//set U
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			{
				U[i][j]=1;
			}
			else if(j<i){
				U[i][j]=0;
			}
			else if(j>i)
			{
				U[i][j]=-3254;
			}
		}
	}
	
	double divideL,divideU;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(i>=j)//L
			{
				sum=0;
				for(k=0;k<n;k++)
				{
					if(k==j)
					{
						divideU = U[k][j];
					}
					else{
						kon=0;
						kon=L[i][k]*U[k][j];
						sum=sum+kon;
					}
				}
				L[i][j] = (A[i][j]-sum)/divideU;
				
			}
			else//U
			{
				sum=0;
				for(k=0;k<n;k++)
				{
					if(k==i)
					{
						divideL = L[i][k];
					}
					else
					{	
						kon=0;
						kon=L[i][k]*U[k][j];
						sum=sum+kon;
					}
					U[i][j] = (A[i][j]-sum)/divideL;
				}
			}
		}
	}
	cout<<"-------------------------------------------------------------------"<<endl;
	//L
	cout<<"L"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<L[i][j]<<"\t\t";
		}
		cout<<endl;
	}
	cout<<"-------------------------------------------------------------------"<<endl;
	//U
	cout<<"U"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<U[i][j]<<"\t\t";
		}
		cout<<endl;
	}
	//Y
	
	cout<<"-------------------------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		sum=0;
		for(k=0;k<n;k++)
		{	
			if(k==i)
			{
				divideL = L[i][k];
			}	
			else{
				kon=0;
				kon=L[i][k]*Y[k];
				sum=sum+kon;
			}		
			
		}
			Y[i] = (B[i]-sum)/divideL;		
	}
	
	cout<<"Y"<<endl;
	for(i=0;i<n;i++)
	{				
		cout<<"Y"<<i+1<<" = "<< Y[i]<<endl;
	}
	
	// x
	cout<<"-------------------------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		U[i][n] = Y[i]; 
	}
	
	for(i=n-1;i>=0;i--)
	{	
		for(int tad=i-1;tad>=0;tad--)
		{		
			double nt =U[tad][i];
			for(j=n;j>=0;j--)
			{
				U[tad][j] = U[tad][j]-(U[i][j]*nt);							
			}
		}	
	}
	
	cout<<"U"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cout<<U[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"X"<<endl;
	
	for(i=0;i<n;i++)
	{				
		X[i] = U[i][n];
		cout<<"X"<<i+1<<" = "<< X[i]<<endl;
	}
	return 0;
}
