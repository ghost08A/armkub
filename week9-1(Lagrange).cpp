#include <iostream>

using namespace std;

int main()
{
	int i,j,k,n;
	double x,y=0,multiply,divide;
	cout<<"Fx() : ";
	cin>>x;
	cin>>n;
	double arrA[n][2],arrnew[n][2];
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
	int l;
	cout<<"How many points are there? :";
	cin>>l;
	double arrL[l];
	int point;
	for(i=0;i<l;i++)//copy arrnew
	{
		cout<<"point"<<i<<" : ";
		cin>>point;
		point=point-1;
		arrnew[i][0] = arrA[point][0];
		arrnew[i][1] = arrA[point][1];
	}
	cout<<"----------------------------------------------------"<<endl;
	for(i=0;i<l;i++)
	{
		cout<<i+1<<" "<<arrnew[i][0]<<" "<<arrnew[i][1]<<endl;
	}
	cout<<"----------------------------------------------------"<<endl;
	for(i=0;i<l;i++)//find L
	{
		multiply=1;divide=1;
		for(j=0;j<l;j++)
		{
			if(i!=j)
			{
				multiply = multiply*(arrnew[j][0]-x);
				divide   = divide*(arrnew[j][0]-arrnew[i][0]); 
			}
		}
		arrL[i] = multiply/divide;
	}
	for(i=0;i<l;i++)// print L
	{
		cout<<"L["<<i<<"] "<<arrL[i]<<endl;
	}
	cout<<"----------------------------------------------------"<<endl;
	for(i=0;i<l;i++)// find y
	{
		y += arrL[i]*arrnew[i][1];
	}
	cout<<"Fx("<<x<<") = "<<y;
	return 0;
}
