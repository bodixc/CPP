#include <iostream>
#include <cmath>
using namespace std;
double func(double t) {
	double func = 3*t*t;
	return func;
}
double Integral(double x, int n) {
	double h = x / n;
	double t = 0;
	double integral_sum = 0;
	for (int i = 0; i < n; i++) {
		integral_sum += func(t)+4*func((t+t+h)/2)+func(t+h);
		t += h;
	}
	double integral = h/6 * integral_sum;
	return integral;
}

double Runge(double x, int n) {
	double a = Integral(x, n);
	double b = Integral(x, 2*n);
	double runge = abs(b - a)/15;
	return runge;
}
	

int main() {
	for (int i = 0; i <= 10; i++) {
		double x = i / 10.0;
		for (int n = 1; n < 3; n++) {
			if (Runge(x, n) > 0.0001) {
				continue;
			}
			else {
				cout << "X: (" << x << "), integral:(" << Integral(x, n) <<"), n: ("<<n<< "), h: (" << x / n << "), mistake:(" << Runge(x, n)<<")"<<endl;
				break;
			}
		}
	}
}