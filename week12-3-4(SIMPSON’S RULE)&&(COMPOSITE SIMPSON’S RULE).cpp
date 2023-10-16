#include <iostream>
#include <math.h>
using namespace std;

double fuc(double x)
{
	return pow(x,7)+2*pow(x,3)-1;
}

double pomarm(int n,double a,double b){
	int i,j;
	double arrH[n];
	double Ikee=0,Ikuu=0,Iaws;
	double h = (b-a)/n;
	for(i=0;i<=n;i++){
		if(i==0){
			arrH[0] = a;
		}
		else{
			arrH[i] = arrH[i-1]+h;
		}
	}
	for(i=0;i<n;i++){
		double aa = (arrH[i]+arrH[i+1])/2;
		
		Ikee += fuc(aa);
	}
	//-----------------------------------------------------------------------------
	for(i=1;i<n;i++){
		Ikuu += fuc(arrH[i]);
	}
	h=(b-a)/(n+1);
	Iaws = (h/3)*(fuc(arrH[0])+fuc(arrH[n])+(4*Ikee)+2*Ikuu);
	
	cout<<Iaws<<endl;
	return 0;
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
		pomarm(num[i],a,b);
	}
	return 0;
} 
