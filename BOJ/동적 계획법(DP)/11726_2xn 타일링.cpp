#include <iostream>
#include <vector>
#define MOD 10007;
using namespace std;
vector<long long> arr;
long long dp(int n);
int main(void) {
	int n;
	cin >> n;
	arr.resize(n + 1);
	cout << dp(n) << '\n';
}
long long dp(int n) {
	if (n == 1) return arr[n] = 1;
	else if (n == 2) return arr[n] = 2;
	if (arr[n] != 0) return arr[n];
	return arr[n] = (dp(n - 1) + dp(n - 2))%MOD;
}