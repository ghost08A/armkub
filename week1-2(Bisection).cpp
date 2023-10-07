#include <iostream>
#include <cmath>
using namespace std;

float formula(float am)
{
	
	return pow(13.0,1.0/4.0)-am;
}

int main()
{
	int i=0;
	float al=1.5,ar=2.0,am=0.0,test=0.000001;
	while(fabs(formula(am)) > test)
	{
		i++;
		am = (al+ar)/2;
		if(formula(am)==0)
		{
			break;
		}
		else if(formula(am)>0)
		{
			al = am;
		}
		else
		{
			ar = am;
		}
		cout<< i<<" am = "<<am<<" al = "<<al<<" ar = "<<ar<<endl;
	}
	cout<<am;
	return 0;
}
