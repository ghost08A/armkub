#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	float arm[n][n+1];
	int i,j,tad;
	//input
	for (i=0;i<n;i++){
		for(j=0;j<=n;j++){
			cin>>arm[i][j];
		}
	}
	
	float nt,ma;
	
	for(i=0;i<n;i++)
	{	
		cout<<i+1<<"----------------------------------------------"<<endl;
		ma = arm[i][i];
		for(tad=i+1;tad<=n;tad++)
			{		
				nt =arm[tad][i];
				for(j=i;j<=n;j++)
				{
					if(tad==i+1)
					{
						arm[i][j] = arm[i][j]/ma;
					}
					arm[tad][j] = arm[tad][j]-(arm[i][j]*nt);							
				}
		}	
		//print
		for (int y=0;y<n;y++)
		{
			for(int u=0;u<=n;u++)
			{
				cout<<arm[y][u]<<"\t";
			}
			cout<<endl;
		}	
	}
	
	float x[n+1];
	for(i=n;i>0;i--)
	{
		x[i] = 0;
	}
	
	int b,u=0;
	
	//  1 2 3
	x[n] = arm[n-1][n];
	float tamp,sum;
	for (i=n-2;i>=0;i--)// 1 0  
	{
		tamp = arm[i][n];
		sum=0;
		for(j=n-1;j>=i;j--)//3 2
		{
			sum += arm[i][j]*x[n-u];
			u++;
			if(j==i)
			{
				x[i+1] =  tamp-sum;
			}
		}
		tamp = 0;
		u=0;
	}
		//print x3 2 1
	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<" = "<<x[i]<<endl;
	}
}
