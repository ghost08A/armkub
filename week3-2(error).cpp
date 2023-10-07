#include <iostream>
#include <cmath>

using namespace std;

double ta(double x, int N) {
    double result = 0.0;
    double x0 = 2.0; 
    double h = x - x0;

    for (int n = 0; n <= N; ++n) {
        if (n == 0) {
            result += log(x0);
        } else if (n == 1) {
            result += (1.0 / 2) * h;
        } else if (n == 2) {
            result += (-1.0 / 8) * h * h;
        } else if (n == 3) {
            result += (2.0 / 24) * h * h * h;
        }
        h *= (x - x0); 
    }
    return result;
}
int main() {
    double x = 4.0;
    double ax = log(x),result,error; 
    for (int N = 0; N <= 3; ++N) {
         result = ta(x, N);
         error = abs(ax - result);
        cout << "N = " << N << " result: " << result << " Error: " << error << endl;
    }
    return 0;
}


