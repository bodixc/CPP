#include <iostream>
#include <cmath>
#include <chrono>
using namespace std;
using namespace std::chrono;
auto start = high_resolution_clock::now();

double global(double xx) {
    double polinom = 0;
    double value_x[10]{
        0.5,0.69, 0.78, 0.99, 1.21, 1.34, 1.51, 1.63, 1.71, 1.83
    };
    double value_f[10]{
        0.55962, 0.77293, 0.87062, 1.0886, 1.30131, 1.41963, 1.566561, 1.66523, 1.72884, 1.82114
    };
    int n = 10;
    for (int i = 0; i < n; i++) {
        double up = 1;
        double down = 1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                up *= (xx - value_x[j]);
                down *= (value_x[i] - value_x[j]);
            }
        }
        polinom += (up / down) * value_f[i];
    }
    return polinom;
}

double local(double xx,int k) {
    double polinom_l = 0;
    double h = 0.01;
    int l = 2;
    double value_x[10]{
        0.5,0.69, 0.78, 0.99, 1.21, 1.34, 1.51, 1.63, 1.71, 1.83
    };
    double value_f[10]{
        0.55962, 0.77293, 0.87062, 1.0886, 1.30131, 1.41963, 1.566561, 1.66523, 1.72884, 1.82114
    };
    for (int i = 0+k; i < l+k; i++) {
        double up = 1;
        double down = 1;
        for (int j = 0+k; j < l+k; j++) {
            if (i != j) {
                up *= (xx - value_x[j]);
                down *= (value_x[i] - value_x[j]);
            }
        }
        polinom_l += (up / down) * value_f[i];
    }
    return polinom_l;
}
int main() {
    for (int ii = 0; ii < 1000000; ii++)
    {
        double b = 1.5;
        double a = 0;
        double h = 0.000000000001;
        //int n = 100;
        int l = 2;
        double value_x[10]{
            0.5,0.69, 0.78, 0.99, 1.21, 1.34, 1.51, 1.63, 1.71, 1.83
        };
        double value_f[10]{
            0.55962, 0.77293, 0.87062, 1.0886, 1.30131, 1.41963, 1.566561, 1.66523, 1.72884, 1.82114
        };

        int values = ((b - a) / h) + 1;
        //значення функції в точках за формулою
        double* range_of_func_x = new double[values];
        for (int i = 0; i < values; i++) {
            double x = i / 100.0;
            range_of_func_x[i] = log(x * x + x + 1);
        }
        //значення похідної 1 за формулою
        double* range_of_diff1_x = new double[values];
        for (int i = 0; i < values; i++) {
            double x = i / 100.0;
            range_of_diff1_x[i] = (2 * x + 1) / (x * x + x + 1);
        }
        //значення похідної 2 за формулою
        double* range_of_diff2_x = new double[values];
        for (int i = 0; i < values; i++) {
            double x = i / 100.0;
            range_of_diff2_x[i] = ((2 * (x * x + x + 1)) - (2 * x + 1) * (2 * x + 1)) / ((x * x + x + 1) * (x * x + x + 1));
        }
        //локальний x
        double* range_of_local_x = new double[values];
        for (int i = 0; i < values; i++) {
            double x = i / 100.0;
            if (i <= 50) {
                int k = 0;
                range_of_local_x[i] = local(x, k);
            }
            else if (i <= 69) {
                int k = 1;
                range_of_local_x[i] = local(x, k);
            }
            else if (i <= 78) {
                int k = 2;
                range_of_local_x[i] = local(x, k);
            }
            else if (i <= 99) {
                int k = 3;
                range_of_local_x[i] = local(x, k);
            }
            else if (i <= 121) {
                int k = 4;
                range_of_local_x[i] = local(x, k);
            }
            else if (i <= 134) {
                int k = 5;
                range_of_local_x[i] = local(x, k);
            }
            else if (i <= 151) {
                int k = 6;
                range_of_local_x[i] = local(x, k);
            }
        }
        //локальна перша похідна
        double* range_of_local_diff1_x = new double[values];
        for (int i = 0; i < values; i++) {
            double x = i / 100.0;
            double a, b;
            if (i == 0) {
                int k = 0;
                a = local(x, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / h;
            }
            else if (i <= 50) {
                int k = 0;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i <= 69) {
                int k = 1;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i <= 78) {
                int k = 2;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i <= 99) {
                int k = 3;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i <= 121) {
                int k = 4;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i <= 134) {
                int k = 5;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i < 150) {
                int k = 6;
                a = local(x - h, k);
                b = local(x + h, k);
                range_of_local_diff1_x[i] = (b - a) / (2 * h);
            }
            else if (i == 150) {
                int k = 6;
                a = local(x - h, k);
                b = local(x, k);
                range_of_local_diff1_x[i] = (b - a) / h;
            }
        }

        //локальна друга похідна
        double* range_of_local_diff2_x = new double[values];
        for (int i = 0; i < values; i++) {
            double x = i / 100.0;
            double a, b, c;
            if (i == 0) {
                range_of_local_diff2_x[i] = 0;
            }
            else if (i <= 50) {
                int k = 0;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - (2 * c)) / (h * h);
            }
            else if (i <= 69) {
                int k = 1;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - 2 * c) / (h * h);
            }
            else if (i <= 78) {
                int k = 2;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - 2 * c) / (h * h);
            }
            else if (i <= 99) {
                int k = 3;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - 2 * c) / (h * h);
            }
            else if (i <= 121) {
                int k = 4;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - 2 * c) / (h * h);
            }
            else if (i <= 134) {
                int k = 5;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - 2 * c) / (h * h);
            }
            else if (i < 150) {
                int k = 6;
                a = local(x - h, k);
                b = local(x + h, k);
                c = local(x, k);
                range_of_local_diff2_x[i] = (b + a - 2 * c) / (h * h);
            }
            else if (i == 150) {
                range_of_local_diff2_x[i] = 0;
            }
        }
        
        //вивід
        /*for (int i = 0; i < values; i++) {
            double c = i / 100.0;
            cout <<"X: "<< c << "  Func value: "<<range_of_func_x[i] <<"  Global: "<<global(c) << "  Local: " << range_of_local_x[i] << "  Diff1 value: " << range_of_diff1_x[i] <<"  Diff1: "<< range_of_local_diff1_x[i]<< "  Diff2 value: " << range_of_diff2_x[i]<<"  Diff2: "<< range_of_local_diff2_x[i] << "  " << endl;
        }*/
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by program: "<< duration.count() << " microseconds" << endl;
}


    
