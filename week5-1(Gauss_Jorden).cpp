#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	float arm[n][n+1];
	int i,j,tad;
	for (i=0;i<n;i++){
		for(j=0;j<=n;j++){
			cin>>arm[i][j];
		}
	}
	float nt,ma;
	
	for(i=0;i<n;i++)
	{	
		
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
	}
	
	for(i=n-1;i>=0;i--)
	{	
		
		for(tad=i-1;tad>=0;tad--)
			{		
				nt =arm[tad][i];
				for(j=n;j>=0;j--)
				{
					arm[tad][j] = arm[tad][j]-(arm[i][j]*nt);							
				}
		}
		
	}
	
	for (i=0;i<n;i++){
		for(j=0;j<=n;j++){
			cout<<arm[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	float x[n+1];
	for(i=1;i<=n;i++)
	{
		x[i] = arm[i-1][n];
	}
	for(i=1;i<=n;i++)
	{
		cout<<"x"<<i<<" = "<<x[i]<<endl;
	}
}
