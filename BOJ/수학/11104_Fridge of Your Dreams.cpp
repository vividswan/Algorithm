#include <iostream>
#include <cmath>
using namespace std;
int main(void) {
	int tk;
	cin >> tk;
	for (int i = 1; i <= tk; i++) {
		int sum = 0;
		char str[25];
		cin >> str;
		for (int i = 0; i <= 23; i++) {
			if (str[i] == '0') continue;
			else sum += pow(2, 24 - i - 1);
		}
		cout << sum << '\n';
	}
}