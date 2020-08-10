#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, value;
		cin >> num >> value;
		if (value == num * (num + 1) / 2) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}