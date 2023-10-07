#include <iostream>
#include <cmath>
using namespace std;
float formula(float am,float root,float rak)
{
	return pow(root,1.0/rak)-am;
}

int main()
{
	int i=0;
	float am=0.0,al,ar,root,rak,test=0.00001;
	cin>>root>>rak;
	al=0;
	ar=root;
	while(fabs(al-ar) > test)
	{
		i++;
		am = (al+ar)/2;
		if(formula(am,root,rak)==0)
		{
			break;
		}
		else if(formula(am,root,rak)>0)
		{
			al = am;
		}
		else
		{
			ar = am;
		}
		cout<< i<<" am = "<<am<<endl;
	}
	cout<<am;
	return 0;
}
