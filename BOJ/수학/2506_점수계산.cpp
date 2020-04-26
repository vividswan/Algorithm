#include <iostream>
using namespace std;
int N;
int total;
int temporaryTotal;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		if (!now) temporaryTotal = 0;
		else {
			temporaryTotal += now;
			total += temporaryTotal;
		}
	}
	cout << total << '\n';
}