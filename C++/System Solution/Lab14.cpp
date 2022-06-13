#include <iostream>
#include <cmath>
using namespace std;
int main() 
{
	double a, b, c, discr, sqrt_discr, x1, x2, x11, x12, x21, x22, y, y1, y2;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	cout << "Input c: ";
	cin >> c;
	discr = (a*a) - (4 * (a - c) * b);
	if (discr > 0) {
		sqrt_discr = sqrt(discr);
		y1 = (a - sqrt_discr) / 2 * b;
		y2 = (a + sqrt_discr) / 2 * b;
		if ((1 - y1) >= 0) {
			x11 = sqrt(1 - y1);
			x12 = -sqrt(1 - y1);
			cout << "The system keys: " << endl;
			cout << "(" << x11 << ";" << y1 << ")" << endl;
			cout << "(" << x12 << ";" << y1 << ")" << endl;
		}
		else {
			cout << "For y1 not found keys!";
		}
		if ((1 - y2) >= 0) {
			x21 = sqrt(1 - y2);
			x22 = -sqrt(1 - y2);
			cout << "(" << x21 << ";" << y2 << ")" << endl;
			cout << "(" << x22 << ";" << y2 << ")" << endl;
		}
		else {
			cout << "For y2 not found keys!";
		}
	}
	else if (discr == 0) {
		discr = sqrt(discr);
		y = a/ (2 * b);
		if ((1 - y) >= 0) {
			x1 = sqrt(1 - y);
			x2 = -sqrt(1 - y);
			cout << "The system keys: " << endl;
			cout << "(" << x1 << ";" << y << ")" << endl;
			cout << "(" << x2 << ";" << y << ")" << endl;
		}
		else {
			cout << "For y not found keys!";
		}
	}
	else {
		cout << "The system don't have any keys!" << endl;
	}
	
}