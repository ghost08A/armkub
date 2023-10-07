#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int i,j,n,k;
	cin>>n;
	double A[n][n+1],sum,kon;
	double L[n][n],U[n][n];
	//A
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			cin>>A[i][j];
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
	cout<<"-----------------------------------------------------------------------"<<endl;
	//L
	cout<<"L"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<L[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	//U
	cout<<"U"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<U[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	return 0;
}
