#include <iostream>
#include <cmath>

using namespace std;

float arm(float am) {
	float aa = pow(13.0, 1.0/4.0) - am;
	cout<<am<<" aa = "<<aa<<endl;
    return aa;
    
}

int main() {
    int i = 0;
    float al = 1.5, ar = 2.0, am = 0, test = 0.0000001;
    while (fabs(arm(am)) > test) 
	{
        i++;
        am = ((al*arm(ar))-(ar*arm(al)))/(arm(ar)-arm(al));
        if (arm(am) == 0){
            break;
        } else if (arm(am)*arm(ar) > 0){
            al = am;
        } else if (arm(am)*arm(ar) < 0){
            ar = am;
        }
        cout << i << " am = " << am << " al = " << al << " ar = " << ar << endl;
    }
    cout << am;
    return 0;
}
