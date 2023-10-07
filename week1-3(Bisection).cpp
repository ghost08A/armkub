#include <iostream>
#include <cmath>
using namespace std;

float formula(float am)
{
	return 1.0/43.0-am;
}

int main()
{
	int i=0;
	float al = 0.02, ar = 0.03, am = 30,test=0.0000001;
	while(fabs(al-ar) > test)
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
