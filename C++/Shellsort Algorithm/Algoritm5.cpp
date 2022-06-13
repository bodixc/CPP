#include <iostream>	
using namespace std;
void Shellsort() {
	int h, a, b;
	int n = 8;
	int A[] = {9,8,7,6,5,4,3,2};
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
	for (h = 1; h <= n / 9; h = h * 3 + 1);
	while (h >= 1) {
		for (int i = h; i < n; i++) {
			for (int j = i - h; j >= 0 && A[j] > A[j + h]; j -= h) {
				a = A[j];
				b = A[j + h];
				A[j] = b;
				A[j + h] = a;

			}
			for (int i = 0; i < n; i++) {
				cout << A[i] << " ";
			}
			cout << "\n";
		}
		h = (h - 1) / 3;
	}
}
void Partition(int L, int R) {
	int n = 8;
	int A[] = { 1,0,1,0,1,0,1,0 };
	int c, d;
	int i = L;
	int j = R;
	int x = A[(L + R) / 2];
	while (i < j) {
		while (A[i] < x) {
			i++;
		}
		while (x < A[j]) {
			j--;
		}
		if (i < j) {
			c = A[i];
			d = A[j];
			A[i] = d;
			A[j] = c;
			i++;
			j--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << "\n";
}


int main() {
	Shellsort();
	Partition(7,0);
}
