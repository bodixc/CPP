#include <iostream>
#include <string>
using namespace std;
int main() {
	int day;
	string month;
	cout << "Input a day: ";
	cin >> day;
	cout << "Input a month: ";
	cin >> month;
	string months[12] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	string days[7] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
		
	};
	int days_in_month[12] = {
		31,28,31,30,31,30,31,31,30,31,30,31
	};
	for (int i = 0; i < 12; i++) {
		if (month == months[i]) {
			if (day <= days_in_month[i]) {

				int sum_days_before = 0;
				for (int a = 0; a < i; a++) {
					sum_days_before += days_in_month[a];
				}
				int sum_days = sum_days_before + day;
				cout << "This day is " << days[(sum_days + 5) % 7 - 1];

			}
			else {
				cout << "Uncorrect data!";
			}
		}
	}
}