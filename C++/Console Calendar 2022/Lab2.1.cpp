#include <iostream>
#include <string>
using namespace std;
int main() {
	int day = 4;
	string months[12] = {
		"January","February","March","April","May","June","July","August","September","October","November","December"
	};
	string days[7] = {
		"Mon","Tue","Wed","Thu","Fri","Sat","Sun"
	};
	int days_in_month[12] = {
		31,28,31,30,31,30,31,31,30,31,30,31
	};
	for (int i = 0; i < 12; i++) {
		cout << months[i] << endl;
		for (int j = 0; j < 7; j++) {
			cout << days[j] << " ";
		}
		cout << endl;
		int sum_days_before = 0;
		for (int a = 0; a < i; a++) {
			sum_days_before += days_in_month[a];
		}
		int sum_days = sum_days_before + day;
		int day_of_week = (sum_days + 2) % 7 - 1;               
		if (day_of_week < 0) {
			day_of_week = 7 + day_of_week;
		}                               
		for (int empty = 0; empty < day_of_week; empty++) { 
			cout << "    ";
		}
		for (int days = 1; days < 8 - day_of_week; days++) {
			cout << days << "   ";
		}
		cout << endl;  
		for (int date = 8 - day_of_week; date <= days_in_month[i]; date += 7) {
			for (int num = date; num < date + 7; num++) {
				if (num > days_in_month[i]) { 
					break;
				}
				if (num < 10) {
					cout << num << "   ";
				}
				else {
					cout << num << "  ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
}
