#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int N, K;
	cin >> N >> K;
	vector<char> adj(N);
	for (int i = 0; i < N; i++) adj[i] = '?';
	int now = 0;
	for (int i = 0; i < K; i++) {
		int cnt;
		char value;
		cin >> cnt >> value;
		cnt %= N;
		now -= cnt;
		if (now < 0) now += N;
		if (adj[now] != '?' && adj[now] != value) {
			cout << "!\n";
			return 0;
		}
		else adj[now] = value;
	}
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (adj[i] != '?' && adj[i] == adj[j]) {
				cout << "!\n";
				return 0;
			}
		}
	}
	int rot = N;
	while (rot--) {
		cout << adj[now];
		now++;
		if (now == N) now = 0;
	}
	cout << '\n';
	return 0;
}