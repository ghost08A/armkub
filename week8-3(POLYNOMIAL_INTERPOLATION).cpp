#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,i,j,k,count=0;
	double x,y=0,multiply;
	cout<<"Fx() : ";
	cin>>x;
	cin>>n;
	double arrA[n][2],arrC[10],arrnew[n][2];
	
	for(i=0;i<n;i++)
	{
		cin>>arrA[i][0]>>arrA[i][1];
	}
	cout<<"----------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" "<<arrA[i][0]<<" "<<arrA[i][1]<<endl;
	}
	cout<<"----------------------------------------------------"<<endl;
	
	int c;
	cin>>c;
	int point;
	for(i=0;i<c;i++)
	{
		cout<<"point"<<i<<" : ";cin>>point;
		point=point-1;
		arrnew[i][0] = arrA[point][0];
		arrnew[i][1] = arrA[point][1];
	}
	cout<<"----------------------------------------------------"<<endl;
	double arrfx[c][2];
	for(i=0;i<c;i++)//coppy
	{
		arrfx[i][0] = arrnew[i][0];
		arrfx[i][1] = arrnew[i][1];
	}
	//set C
	arrC[0] = arrnew[0][1];
	for(i=1;i<c;i++)
	{
		for(j=0;j<c-i+1;j++)
		{
			if(i==1)
			{
				arrfx[j][1] = (arrnew[j+1][1]-arrnew[j][1])/(arrnew[j+1][0]-arrnew[j][0]);
			}
			else
			{
				arrfx[j][1] = (arrfx[j+1][1]-arrfx[j][1])/(arrnew[i+j][0]-arrnew[j][0]);
			}
		}
		arrC[i] =arrfx[0][1]; //save C
	}
	
	for(i=0;i<c;i++)
	{
		cout<<"C["<<i<<"] "<<arrC[i]<<endl;
	}
	cout<<"----------------------------------------------------"<<endl;
	
	y = arrC[0];
	for(i=1;i<c;i++)
	{
		multiply=1;
		for(j=0;j<i;j++)
		{
			multiply = multiply*(x-arrnew[j][0]);
		}
		y += multiply*arrC[i];
	}
	cout<<"Fx = "<<y;
	return 0;
}
