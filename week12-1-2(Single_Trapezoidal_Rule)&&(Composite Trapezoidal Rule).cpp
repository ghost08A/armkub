#include <iostream>
#include <math.h>
using namespace std;

double fuc(double x)
{
	return 4*pow(x,5)-3*pow(x,4)+pow(x,3)-6*x+2;
}

double pomarm(int n,double a,double b){
	int i;
	double arrH[n];
	double Isum=0,Iaws;
	double h = (b-a)/n;
	for(i=0;i<=n;i++){
		if(i==0){
			arrH[0] = a;
		}
		else{
			arrH[i] = arrH[i-1]+h;
		}
	}
	for(i=0;i<=n;i++){
		cout<<arrH[i]<<" ";
	}
	cout<<endl;
	for(i=1;i<n;i++){
		Isum += fuc(arrH[i]);
	}
	Iaws = (h/2)*(fuc(arrH[0])+fuc(arrH[n])+2*Isum);
	return Iaws;
}

int main(){
	int n;
	double a,b;
	cout<<"a = ";
	cin>>a;
	cout<<"b = ";
	cin>>b;
	cout<<"cout = ";
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
		cout<<pomarm(num[i],a,b)<<endl;
	}
	return 0;
} 
