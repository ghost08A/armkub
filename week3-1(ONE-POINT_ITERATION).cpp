#include <iostream>
#include <cmath>

using namespace std;
double g(double x)
{
	return ((4*pow(x,2))+1)/4;
}
int main(){
	double x0=0.00,x1=1,test = 0.000001;
	int i=0;
	while(fabs(x1-x0)/x1>test)
	{
		x1=x0;
		x0=g(x1);
		i++;
		cout<<i<<" "<<x0<<endl;
	}
	return 0;
}
