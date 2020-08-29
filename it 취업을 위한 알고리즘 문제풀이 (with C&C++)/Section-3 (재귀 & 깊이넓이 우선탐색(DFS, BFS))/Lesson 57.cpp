#include <iostream>
using namespace std;
void recursion(int N);
int main(void) {
	int N;
	cin >> N;
	recursion(N);
	cout << '\n';
	return 0;
}
void recursion(int N) {
	if (!N) return;
	recursion(N / 2);
	cout << N % 2;
}