#include <iostream>
#include <cmath>
using namespace std;
double func2(double x) {
	double y = sin(x + 2) - 1.5;
	return y;
}
double func1(double y) {
	double x = -cos(y - 2) + 0.5;
	return x;
}
double max(double a, double b) {
	if (a > b) {
		return a;
	}
	else return b;
}

double sys1(double x2, double x3) {
	double x1 = (1.9 - 2.7 * x2 + 1.7 * x3) / 5.6;
	return x1;
}
double sys2(double x1, double x3) {
	double x2 = (1.9 - 0.6 * x1 + 2.4 * x3) / 3.7;
	return x2;
}
double sys3(double x1, double x2) {
	double x3 = (1.2 - 0.8 * x1 - 1.3 * x2) / 3.7;
	return x3;
}double maxx(double a, double b, double c) {
	if (a > b) {
		if (a > c) {
			return a;
		}
		else return c;
	}
	else {
		if (b > c) {
			return b;
		}
		else return c;
	}
}
int main() {
	double x0 = 1.5;
	double y0 = -1.5;
	double xk_1 = x0;
	double yk_1 = y0;
	double delta = x0;
	double xk, yk,a,b;

	cout <<"1st system\nSimple iteration\n"<< "k: 0; x(k): ("<<x0<<"; "<< y0<<"); delta: -" << endl;
	for (int i = 1; i < 100; i++) {
		if (delta > 0.0001) {
			xk = func1(yk_1);
			yk = func2(xk_1);
			a = abs(xk - xk_1);
			b = abs(yk - yk_1);
			delta = max(a, b);
			cout << "k: " << i << "; x(k): (" << xk << "; " << yk << "); delta: " << delta << endl;
			xk_1 = xk;
			yk_1 = yk;
		}
	}
	cout << "r: (" << func1(yk) - xk << "; " << func2(xk) - yk << ")\n\n";

	cout << "1st system\nZeidel\n" << "k: 0; x(k): (" << x0 << "; " << y0 << "); delta: -" << endl;
	delta = x0;
	xk_1 = x0;
	yk_1 = y0;
	a = 0;
	b = 0;
	for (int i = 1; i < 100; i++) {
		if (delta > 0.0001) {
			xk = func1(yk_1);
			yk = func2(xk);
			a = abs(xk - xk_1);
			b = abs(yk - yk_1);
			delta = max(a, b);
			cout << "k: " << i << "; x(k): (" << xk << "; " << yk << "); delta: " << delta << endl;
			xk_1 = xk;
			yk_1 = yk;
		}
	}
	cout << "r: (" << func1(yk) - xk << "; " << func2(xk) - yk << ")\n";

	double x10 = 1.9 / 5.6;
	double x20 = 1.9 / 3.7;
	double x30 = 1.2 / 3.7;
	double x1k_1 = x10;
	double x2k_1 = x20;
	double x3k_1 = x30;
	double deltaa = x0;
	double x1k, x2k, x3k, c, d, e;

	cout << "\n2st system\nSimple iteration\n" << "k: 0; x(k): (" << x10 << "; " << x20 << "; " << x30 << "); delta: -" << endl;
	for (int i = 1; i < 100; i++) {
		if (deltaa > 0.0001) {
			x1k = sys1(x2k_1, x3k_1);
			x2k = sys2(x1k_1, x3k_1);
			x3k = sys3(x1k_1, x2k_1);
			c = abs(x1k - x1k_1);
			d = abs(x2k - x2k_1);
			e = abs(x3k - x3k_1);
			deltaa = maxx(c,d,e);
			cout << "k: " << i << "; x(k): (" << x1k << "; " << x2k << "; "<<x3k<<"); delta: " << deltaa << endl;
			x1k_1 = x1k;
			x2k_1 = x2k;
			x3k_1 = x3k;
			
		}
	}
	cout << "r: (" << sys1(x2k,x3k) - x1k << "; " << sys2(x1k, x3k) - x2k << "; " <<sys3(x1k, x2k) - x3k<< ")\n";

	cout << "\n2st system\nZeidel\n" << "k: 0; x(k): (" << x10 << "; " << x20 << "; " << x30 << "); delta: -" << endl;
	deltaa = x10;
	x1k_1 = x10;
	x2k_1 = x20;
	x3k_1 = x30;
	c = 0;
	d = 0;
	e = 0;
	for (int i = 1; i < 100; i++) {
		if (deltaa > 0.0001) {
			x1k = sys1(x2k_1, x3k_1);
			x2k = sys2(x1k, x3k_1);
			x3k = sys3(x1k, x2k);
			c = abs(x1k - x1k_1);
			d = abs(x2k - x2k_1);
			e = abs(x3k - x3k_1);
			deltaa = maxx(c, d, e);
			cout << "k: " << i << "; x(k): (" << x1k << "; " << x2k << "; " << x3k << "); delta: " << deltaa << endl;
			x1k_1 = x1k;
			x2k_1 = x2k;
			x3k_1 = x3k;

		}
	}
	cout << "r: (" << sys1(x2k, x3k) - x1k << "; " << sys2(x1k, x3k) - x2k << "; " << sys3(x1k, x2k) - x3k << ")\n";
}