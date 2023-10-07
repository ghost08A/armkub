#include <iostream>
#include <cmath>
using namespace std;

double C_C(double arrnew[100][2],int start,int end)
{
	if(fabs(start-end)==1)
	{
		return  (arrnew[start][1]-arrnew[end][1])/(arrnew[start][0]-arrnew[end][0]);
	}
	else
	{
		return (C_C(arrnew,start,end+1)-C_C(arrnew,start-1,end))/(arrnew[start][0]-arrnew[end][0]);
	}
}
int main()
{
	int n,i,j;
	double x,y=0;
	cout<<"Fx() : ";
	cin>>x;
	cin>>n;
	double arrA[n][2],arrC[10],arrnew[n][2];
	//add
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
		cout<<"point"<<i<<" : ";
		cin>>point;
		point=point-1;
		arrnew[i][0] = arrA[point][0];
		arrnew[i][1] = arrA[point][1];
	}
	cout<<"----------------------------------------------------"<<endl;
	//set C
	for(i=0;i<c;i++)
	{
		if(i==0)
		{
			arrC[i] = arrnew[i][1];
		}
		else
		{
			arrC[i] = C_C(arrnew,i,0);
		}
	}
	
	for(i=0;i<c;i++)
	{
		cout<<"C["<<i<<"] "<<arrC[i]<<endl;
	}
	cout<<"----------------------------------------------------"<<endl;
	
	double multiply=1;
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
