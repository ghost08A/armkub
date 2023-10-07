#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin>>n;
	float arm[n][n+n];

	int i,j,tad;
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>arm[i][j];
		}
	}
	int m= n+n;
	for (i=0;i<n;i++){
		for(j=n;j<m;j++){
			if(i==j%3)
			{
				arm[i][j]=1;
			}
			else{
				arm[i][j] = 0;
			}
		}
	}
	
	for (i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(j==n)
			{
				cout<<"| ";
			}
			cout<<arm[i][j]<<"\t";
		}
		cout<<endl;
	}
	//show100
	
	float nt,ma;
	for(i=0;i<n;i++)
	{	
		ma = arm[i][i];
		for(tad=i+1;tad<=n;tad++)
		{		
			nt =arm[tad][i];
			for(j=i;j<m;j++)
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
				for(j=m-1;j>=0;j--)
				{
					arm[tad][j] = arm[tad][j]-(arm[i][j]*nt);
											
				}
		}
		
	}
	cout<<endl;
	for (i=0;i<n;i++){
		for(j=n;j<m;j++){
			cout<<arm[i][j]<<"\t";
		}
		cout<<endl;
	}
	
}
