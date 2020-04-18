#include <iostream>
using namespace std;
int main(void) {
	int n, m;
	cin >> n >> m;
	int res = 0;
	cout << n * (m % 10) << '\n';
	res += n * (m % 10);
	cout << n * (m % 100 / 10)  << '\n';
	res += n * (m % 100 / 10)*10;
	cout << n * (m / 100)  << '\n';
	res += n * (m / 100) * 100;
	cout << res << '\n';
	return 0;
}
