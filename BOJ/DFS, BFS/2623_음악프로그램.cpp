#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<int> adj[1001];
queue<int> q;
int main(void) {
	int n, m, arr[1001] = { 0, }, line[1001] = { 0, }, cnt = 0, ans[1001], vis[1001] = { 0, };
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int lot;
		cin >> lot;
		for (int i = 0; i < lot; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < lot - 1; i++) {
			adj[arr[i]].push_back(arr[i + 1]);
			line[arr[i + 1]]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (line[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		if (vis[now] == 1) {
			cout << 0;
			break;
		}
		ans[cnt] = now;
		vis[now]++;
		cnt++;
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			line[next]--;
			if (line[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			cout << 0;
			return 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n';
	}
	return 0;
}