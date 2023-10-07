#include<iostream>
#include<math.h>
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
int main() {
   int n, i, j;
   double matrix[15][15];
   double b[15]; 
   cin >> n;
   for (i = 0; i < n; i++) {
       for (j = 0; j <= n; j++) {
           if (j == n) {
               cin >> b[i];
           } else {
               cin >> matrix[i][j];
           }
       }
   }

   double det = determinant(matrix, n);
   cout<<det<<endl;
   double x[n];
   for (j = 0; j < n; j++) {
           cout<<b[j]<<endl; 
       }
   double newarr[15][15]; 

   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           newarr[j][i] = matrix[j][i]; 
       }
   }
   
   for (i = 0; i < n; i++) {
       for (j = 0; j < n; j++) {
           newarr[j][i] = b[j]; 
       }
       x[i] = determinant(newarr, n) / det;
       
       for (int h = 0; h < n; h++) {
           newarr[h][i] = matrix[h][i]; 
       }
   }
   cout << "Solution:" << endl;
   for (i = 0; i < n; i++) {
       cout << "x" << i + 1 << " = " << x[i] << endl;
   }

   return 0;
}
