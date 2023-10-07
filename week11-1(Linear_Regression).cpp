#include <iostream>
#include <math.h>
using namespace std;
double determinant(double matrix[2][3]) {
	return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
}
int main(){
	double x,y,Mxi=0,Mxi2=0,Myi=0,Mxy=0;
	cout<<"f(x) = ";
	cin>>x;
	int n,i,j;
	cin>>n;
	double arrA[n][2],arrcal[2][3],a[2],copy[2];
	for(i=0;i<n;i++)
	{
		cin>>arrA[i][0]>>arrA[i][1];
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	for(i=0;i<n;i++)
	{
		Mxi += arrA[i][0];
		Mxi2 += pow(arrA[i][0],2);
		Myi += arrA[i][1];
		Mxy += arrA[i][0]*arrA[i][1];
	}
	arrcal[0][0] = n;
	arrcal[0][1] = Mxi;
	arrcal[0][2] = Myi;
	arrcal[1][0] =  Mxi;
	arrcal[1][1] = Mxi2;
	arrcal[1][2] = Mxy;
	for(i=0;i<2;i++)
	{
		for(j=0;j<=2;j++)
		{
			cout<<arrcal[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	double det = determinant(arrcal);
	 for (i = 0; i < 2; i++) {
       for (j = 0; j < 2; j++) {
       		copy[j] = arrcal[j][i];
        	arrcal[j][i] = arrcal[j][2]; 
       }
       a[i] = determinant(arrcal) / det;
       
       for (int h = 0; h < n; h++) {
           arrcal[h][i] = copy[h]; 
       }
   }
	for(i=0;i<2;i++)
	{
		cout<<"a"<<i<<" = "<<a[i]<<"\t";
		cout<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	y= a[0]+(a[1]*x);
	cout << "f(" << x << ") = " << y ;
	return 0;
}
