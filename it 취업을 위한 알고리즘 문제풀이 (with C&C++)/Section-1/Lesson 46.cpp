#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int N;
	int sum = 0;
	cin >> N;
	vector<int> adj;
	for(int i = 0; i < N; i++) {
		int num;
		cin >> num;
		sum += num;
		adj.push_back(num);
	}
	int K;
	cin >> K;
	if (sum <= K) {
		cout << -1 << '\n';
		return 0;
	}
	int ptr = -1;
	int cnt = 0;
	while (true) {
		ptr++;
		if (ptr >= N) ptr = 0;
		if (adj[ptr] == 0) continue;
		adj[ptr]--;
		cnt++;
		if (cnt == K) break;
	}
	while (true) {
		ptr++;
		if (ptr >= N) ptr = 0;
		if (adj[ptr] == 0) continue;
		break;
	}
	cout << ptr + 1 << '\n';
	return 0;
}