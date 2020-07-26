#include <iostream>
using namespace std;
int main(void) {
	int N, sum = 0;
	cin >> N;
	cout << 1;
	sum += 1;
	for (int i = 2; i < N; i++) {
		if (!(N % i)) {
			cout << " + " << i;
			sum += i;
		}
	}
	cout << " = " << sum;
	return 0;
}