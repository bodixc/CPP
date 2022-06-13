#include <iostream>
#include <cmath>
using namespace std;
double func(double x) {
	double value = x * x - 4; //x + pow(x, (1.0 / 2)) + pow(x, (1.0 / 3)) + pow(x, (1.0 / 4)) - 5;
	return value;
}
double diff1(double x) {
	double value = 2 * x;// 1 + 1.0 / 2 * pow(x, (1.0 / 2)) + 1.0 / 3 * pow(x, (2.0 / 3)) + 1.0 / 4 * pow(x, (3.0 / 4));
	return value;

}
double diff2(double x) {
	double value = 2;// -3.0 / 16 * pow(x, (7.0 / 4)) - 2.0 / 9 * pow(x, (5.0 / 3)) - 1.0 / 4 * pow(x, (3.0 / 2));
	return value;
}
int main() {
	cout << "Bisection" << endl;
	double a = -3;
	double b = -1;
	double c, x, f, q;
	for (int i = 0; i < 100; i++) {
		if (abs(a - b) > 0.0001) {
			c = abs(b - a);
			x = (a + b) / 2;
			f = func(x);
			if (f == 0) {
				cout << "K: " << i << " a:" << a << ", x:" << x << ", b:" << b << ", |b-a|:" << c << ", f(x):" << f << endl;
				break;
			}
			q = func(a) * func(x);
			cout << "K: " << i << " a:" << a << ", x:" << x << ", b:" << b << ", |b-a|:" << c << ", f(x):" << f << endl;
			if (q < 0) {
				b = x;
			}
			else {
				a = x;
			}

		}
		else {
			c = abs(b - a);
			x = (a + b) / 2;
			f = func(x);
			q = func(a) * func(x);
			cout << "K: " << i << " a:" << a << ", x:" << x << ", b:" << b << ", |b-a|:" << c << ", f(x):" << f << endl;
			break;
		}
	}
	cout << "Newton" << endl;
	a = 1;
	double w = func(a) * diff2(a);
	double xx, ff, d;
	double xxx = 0;
	if (w > 0) {
		xx = a;
	}
	else {
		xx = b;
	}
	d=abs(xx - xxx);
	ff = func(xxx);
	cout << "K: " << 0 << ", x:" << xx << ", |x-x|:" << xx << ", f(x):" << ff << endl;
	for (int i = 1; i < 100; i++) {
		if (d > 0.0001) {
			xxx = xx - func(xx) / diff1(xx);
			ff = func(xxx);
			d = abs(xx - xxx);
			cout << "K: " << i << ", x:" << xxx << ", |x-x|:" << d << ", f(x):" << ff << endl;
			if (ff == 0) {
				cout << "K: " << i << ", x:" << xxx << ", |x-x|:" << d << ", f(x):" << ff << endl;
			}
			xx = xxx;
		}
	}

}
	
	