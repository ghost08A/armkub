#include <iostream>
#include <math.h>
using namespace std;

double determinant(double matrix[15][15],int n) {
    double det = 0;
   double submatrix[15][15];
   if (n == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < n; x++) {
         int subi = 0;
         for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x]*determinant(submatrix, n - 1 ));
      }
   }
   return det;
}
//main
int main(){
	double x,y=0;
	cout<<"f(x) = ";
	cin>>x;
	int n,i,j,m;
	cin>>n;
	double arrA[n][2],arrcal[15][15];
	for(i=0;i<n;i++)
	{
		cin>>arrA[i][0]>>arrA[i][1];
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	cin>>m;
	double mpow[m*2];m++;
	double a[m],ypow[m],copy[m];
	for(i=0;i<(m-1)*2;i++)//mpow
	{
		mpow[i] = 0;
		for(j=0;j<n;j++)
		{
			mpow[i] += pow(arrA[j][0],i+1);
		}
	}//Endmpow
	
	for(i=0;i<m;i++)//ypow
	{
		ypow[i] = 0;
		for(j=0;j<n;j++)
		{
			if(i==0)
			{
				ypow[i] += arrA[j][1];
			}
			else
			{
				ypow[i] += pow(arrA[j][0],i)*arrA[j][1];
			}
		}
	}//Endypow

	for(i=0;i<m;i++)//arrcal
	{
		for(j=0;j<m;j++)
		{
			if(i==0)
			{
				if(j==0)
				{
					arrcal[i][j] = n;
				}
				else
				{
					arrcal[i][j] = mpow[j-1];	
				}
			}
			else{
				arrcal[i][j] = mpow[j+i-1];
			}
		}
	}//End arrcal
	for(i=0;i<m;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(j!=m)
			{
				cout<<arrcal[i][j]<<"\t\t";
			}
			else{
				cout<<ypow[i];
			}
		}
		cout<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	double det = determinant(arrcal,m);
	cout<<det<<endl;
	 for (i = 0; i < m; i++){
       for (j = 0; j < m; j++){
       		copy[j] = arrcal[j][i];
        	arrcal[j][i] = ypow[j];
       }
       a[i] = determinant(arrcal,m) / det;
       for (int h = 0; h < m; h++) {
           arrcal[h][i] = copy[h];
       }
   }
	for(i=0;i<m;i++)
	{
		cout<<"a"<<i<<" = "<<a[i]<<"\t";
		cout<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	
	for(i=0;i<m;i++)
	{
		if(i==0)
		{
			y = a[i];
		}
		else{
			y += a[i]*pow(x,i);
		}
	}
	cout << "f(" << x << ") = " << y ;
	return 0;
}
