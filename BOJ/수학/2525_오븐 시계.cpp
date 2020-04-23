#include <iostream>
using namespace std;
int main(void) {
	int nowHour;
	int nowMinutes;
	int timeValue;
	cin >> nowHour >> nowMinutes;
	cin >> timeValue;
	nowMinutes += timeValue;
	nowHour += nowMinutes / 60;
	nowHour %= 24;
	nowMinutes %= 60;
	cout << nowHour << ' ' << nowMinutes << '\n';
	return 0;
}