#include <iostream>
using namespace std;
void recursion(int N);
int main(void) {
	int N;
	cin >> N;
	recursion(N);
	return 0;
}
void recursion(int N) {
	if (N == 1) {
		cout << 1 << ' ';
		return;
	}
	recursion(N - 1);
	cout << N << ' ';
}