#include <iostream>
#include <math.h>
using namespace std;
float formula(float x)
{
	return 43*x-180;
}
int main()
{
	float i=0.0,x=0.0,m=1000.0,j=0.000001,xl=0.0,xr=0.0;
	while(x<=10)
	{
		if(formula(x)==0)
		{
			break;
		}
		else if(fabs(formula(x)<m)){
			m = fabs(formula(x));
			x++;
		}
		else{
			x--;
			break;
		}
	}
	cout<<x<<endl;
	xl=x;
	xr=x+1;
	while(formula(x)!=0)
	{
		x=x+j;
	}
	cout<<x;
	return 0;
}
