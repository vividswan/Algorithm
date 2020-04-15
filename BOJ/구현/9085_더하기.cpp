#include <iostream>
using namespace std;
int t;
int main(void) {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			int val;
			cin >> val;
			res += val;
		}
		cout << res << '\n';
	}
	return 0;
}