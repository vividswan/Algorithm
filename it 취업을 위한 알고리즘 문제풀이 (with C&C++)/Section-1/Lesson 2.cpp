#include <iostream>
using namespace std;
int main(void) {
	int A, B, sum = 0;
	cin >> A >> B;
	for (int i = A; i < B; i++) {
		sum += i;
		cout << i << "+ ";
	}
	cout << B;
	sum += B;
	cout << '='<< sum;
	return 0;
}