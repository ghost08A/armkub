#include <iostream>
#include <cmath>

using namespace std;

float g(float x)
{
	return (((1849*x*x)+1)/86);
}

int main()
{
	int i=0;
	double x0=54654,x1=0.01;
	while(fabs(x1-x0/x1)>0.00001&&i<1000)
	{
		x0 = x1;
		x1=g(x0);
		i++;
		cout<<i<<" "<<x0<<endl;
	}
	return 0;
}
