#include <iostream>
using namespace std;
char str[15], gender;
int age;
int main(void) {
	cin >> str;
	age += (str[0] - '0') * 10;
	age += str[1] - '0';
	if (age > 10) age += 1900;
	else age += 2000;
	if (str[7] == '1' || str[7] == '3') gender = 'M';
	else gender = 'W';
	cout << 2019 - age + 1 << ' ' << gender << '\n';
	return 0;
}