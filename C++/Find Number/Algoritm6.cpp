#include <iostream>		
using namespace std;
int main()
{
    int num,key;
    cout << "Enter array size: \n";
    cin >> num;
    int n = num + 1;
    int* arrayy = new int[n];
    for (int i = 0; i < n; i++) {
        if (i == num) {
            cout << "Enter key: \n";
            cin >> arrayy[i];
            key = arrayy[i];
        }
        else cin >> arrayy[i];
    }
    cout << "[";
    for (int i = 0; i < num; i++) {
        if (i != num - 1) {
            cout << arrayy[i] << "; ";
        }
        else {
            cout << arrayy[i];
        }
    }
    cout << "]\n";
    int a;
    for (int i = 0; i < n; i++) {
        a = arrayy[i];
        if (a == key) { cout << i;}
        else if ((a!=key) & (a == n)) cout << i;
    }
}