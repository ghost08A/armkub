#include <iostream>
#include <cmath>

using namespace std;
double g(double x)
{
    return ((pow(x,2)-2*(pow(7,1/2.0)*x)+7));
}
double fa(double x){
    return 2*x-2*pow(7,1/2.0);
}
int main(){
    double x1=2.0,x0=3,test = 0.000001;
    int i=0;
    while(fabs(x1-x0)/x1>test)
    {
        x0=x1;
        x1=x0-(g(x0)/fa(x0));
        i++;
        cout<<i<<" "<<x0<<endl;
    }
    return 0;
}
