#include <iostream>

using namespace std;

int main()
{

    int n;
    int stars;
    int points;
    cout << "Number of stars at the base: ";
    cin >> stars;
    cout <<endl<< "Number of figures: ";
    cin >> points;

        
        if (stars % 2 == 0) {         //для парних зірок//
            n = 0;                    //умова для середини 2х зірок//
            stars = stars / 2;
            for (int k = 0; k < points; k++) {   //кількість пірамідок//
                for (int i = stars; i > n; i -= 1) {               //верх пірамідки//
                    for (int star = 0; star < (stars - i); star++) {
                        cout << " ";
                    }

                    for (int empty = 1; empty <= 2 * i; empty++) {
                        cout << "*";
                    }


                    cout << endl;
                }
                for (int i = 2; i < stars + 1; i++) {                //низ пірамідки//
                    for (int star = 0; star < (stars - i); star++) {
                        cout << " ";
                    }

                    for (int empty = 1; empty <= 2 * i; empty++) {
                        cout << "*";
                    }


                    cout << endl;
                }
                cout << endl;
            }
        }
        else {                        //для непарних//
            n = 1;                    //умова для середини 3х зірок//
            stars = stars / 2 + 1;
            for (int k = 0; k < points; k++) {   //кількість пірамідок//
                for (int i = stars; i > n; i -= 1) {
                    for (int star = 0; star < (stars - i); star++) {
                        cout << " ";
                    }

                    for (int empty = 1; empty <= 2 * i - 1; empty++) {
                        cout << "*";
                    }


                    cout << endl;
                }
                for (int i = 3; i < stars + 1; i++) {                //низ пірамідки//
                    for (int star = 0; star < (stars - i); star++) {
                        cout << " ";
                    }

                    for (int empty = 1; empty <= 2 * i - 1; empty++) {
                        cout << "*";
                    }


                    cout << endl;
                }
                cout << endl;
            }
        }
    }




