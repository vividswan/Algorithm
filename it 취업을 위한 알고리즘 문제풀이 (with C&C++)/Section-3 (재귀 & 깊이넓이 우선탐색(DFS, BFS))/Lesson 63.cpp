#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	vector<vector<int>>map(N + 1, vector<int>(N + 1));
	vector<vector<pair<int,int>>>adj(N + 1);
	for (int i = 0; i < M; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		adj[st].push_back({ ed, val });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < adj[i].size(); j++) {
			int st = i;
			int ed = adj[i][j].first;
			int val = adj[i][j].second;
			map[st][ed] = val;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}