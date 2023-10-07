/*
input
3
4 -4 0 400
-1 4 -2 400
0 -2 4 400
100
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,i,j,k,count=0;
	cin>>n;
	double arrA[n][n],arrX[n][2],arrB[n],test=0.000001;
	double sum=0,kon=0,start=0,cheak[n],cheak1=-1;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(j==n)
			{
				cin>>arrB[i];
			}
			else
			{
				cin>>arrA[i][j];
			}
		}
	}
	
	//set X 
	for(i=0;i<n;i++)
	{
		cout<<"start"<<i+1<<" = ";
		cin>>start;
		arrX[i][1]=start;
		cheak[i] = -1;
	}
	
	cout<<"--------------------------------------------------------------------------"<<endl;
	double divide;
	while(true)
	{
		count++;
		// loop for stop
		for(i = 0;i<n;i++)
		{
			if(fabs((arrX[i][1]-arrX[i][0])/arrX[i][1])<test)
			{
				cheak[i] = 0;
			}
			else
			{
				cheak[i] = -1;
			}
		}
		for(i=0;i<n;i++)
		{
			if(cheak[i]!=-1)
			{
				cheak1= 0;
			}
			else
			{
				cheak1 =-1;
			}
		}
		if(count>=100)
		{
			cheak1 = 0;
		}
		if(cheak1 !=-1)
		{
			break;
		}
		//find X
		else{
			for(j=0;j<n;j++)
			{
				arrX[j][0] = arrX[j][1];
			}
			for(i=0;i<n;i++)
			{
				if(cheak[i]==-1)
				{
					sum = 0;
					for(k=0;k<n;k++)
					{
						if(k==i)
						{
							divide = arrA[i][k];
						}
						else
						{
							kon = 0;
							kon = arrX[k][0]*arrA[i][k];
							sum += kon; 
						}
					}
					arrX[i][1] = (arrB[i]-sum)/divide;
				}
			}
		}
		cout<<count<<endl;
		for(i=0;i<n;i++)
		{				
			cout<<"X"<<i+1<<" = "<< arrX[i][0]<<endl;
		}
		cout<<"--------------------------------------------------------------------------"<<endl;
	}
	return 0;
}
