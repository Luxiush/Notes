/*leetcode powx-n*/
/*求x的n次方*/

#include <iostream>

using namespace std;

	//通过
    double pow(double x, int n) {
        if(n == 0) return 1;
        if(n < 0) return 1 / x * pow(1 / x, - (n + 1));
        if(n % 2 == 0) return pow(x * x, n / 2);
        else return pow(x * x, n / 2) * x;
    }
	//没过
    double pow2(double x, int n) {
        if(n<0) return 1/pow(x, -n);
        else if (n==0) return 1;
        else if (n==1) return x;
         
        double temp = pow(x, n/2);
        temp *= temp;
        if(n%2==1) temp *= x;
        return temp;
    }


int main(){
	double x;
	int n;
	cin>> x>> n;
	printf("%.5f\n", pow(x,n));

	return 0;
}