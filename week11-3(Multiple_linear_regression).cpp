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
	double y=0,sum=0;	
	int n,i,j,m,k;
	cin>>n>>m;
	double arrA[n][m],arry[n],arrcal[15][15],x[m];
	for(i=0;i<m;i++)
	{
		cout<<"X"<<i<<" : ";
		cin>>x[i];
	}
	for(i=0;i<n;i++){
		for(j=0;j<=m;j++)
		{
			if(j==m)
			{
				cin>>arry[i];
			}
			else{
				cin>>arrA[i][j];
			}
		}
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	m++;
	double caly[m],a[m],copy[n];
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			sum = 0;
			if(i==0&&j==0)
			{
				arrcal[i][j]=n;
			}
			else if(i==0)
			{
				for(k=0;k<n;k++)
				{
					sum += arrA[k][j-1];
				}
				arrcal[i][j] = sum;
			}
			else if(i>j)
			{
				arrcal[i][j] = arrcal[j][i];
			}
			else if(i<j)
			{
				for(k=0;k<n;k++)
				{
					sum += arrA[k][i-1]*arrA[k][j-1];
				}
				arrcal[i][j] = sum;
			}
			else if(i==j)
			{
				
				for(k=0;k<n;k++)
				{
					
					sum += arrA[k][i-1]*arrA[k][i-1];
				}
				arrcal[i][j] = sum;
			}
		}
		caly[i]=0;
		for(k=0;k<n;k++){
			if(i==0){
				caly[i] += arry[k];  
			}
			else{
				caly[i] += arry[k]*arrA[k][i-1];
			}	 
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(j!=m)
			{
				cout<<arrcal[i][j]<<"\t";
			}
			else{
				cout<<caly[i]<<"\t";
			}
		}
		cout<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	double det = determinant(arrcal,m);
	 for (i = 0; i < m; i++){
       for (j = 0; j < n; j++){
       		copy[j] = arrcal[j][i];
        	arrcal[j][i] = caly[j];
       }
       a[i] = determinant(arrcal,m) / det;
       for (int h = 0; h < n; h++) {
           arrcal[h][i] = copy[h];
       }
   }
	for(i=0;i<m;i++){
		cout<<"a"<<i<<" = "<<a[i]<<"\t";
		cout<<endl;
	}
	cout<<"----------------------------------------------------------------------------------------------------------------"<<endl;
	for(i=0;i<m;i++)
	{
		if(i==0){
			y = a[i];
		}
		else{
			y += a[i]*x[i-1];
		}
	}
	
	cout<<"y = "<<y;
	return 0;
}
