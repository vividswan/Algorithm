#include<iostream>
#include<vector>
void recursion(int level, int sum);
using namespace std;
int result;
int N, M;
vector<int> adj;
int main(void) {
	cin >> N;
	cin >> M;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		adj.push_back(num);
	}
	recursion(1, 0);
	if (result) cout << result << '\n';
	else cout << -1 << '\n';
	return 0;
}
void recursion(int level, int sum) {
	if (level == N + 1) {
		if (sum == M) result++;
		return;
	}
	recursion(level + 1, sum + adj[level - 1]);
	recursion(level + 1, sum - adj[level - 1]);
	recursion(level + 1, sum);
}