#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 15746
using namespace std;
int main(void) {
	int N;
	cin >> N;
	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}
	vector<long long> adj(N + 1);
	adj[1] = 1;
	adj[2] = 2;
	for (int i = 3; i <= N; i++) {
		adj[i] = (adj[i - 1] + adj[i - 2]) % MOD;
	}
	cout << adj[N] % MOD << '\n';
	return 0;
}