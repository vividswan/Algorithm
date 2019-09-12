#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int wait[10001], line[10001], dis[10001], res_max, res[10001];
vector<int> adj[10001];
queue<int> q;
int main(void) {
	int roof;
	cin >> roof;
	for (int i = 1; i <= roof; i++) {
		int last = i;
		cin >> wait[i];
		int a;
		cin >> a;
		if (a == 0) continue;
		else {
			for (int i = 1; i <= a; i++) {
				int b;
				cin >> b;
				adj[b].push_back(last);
				line[last]++;
			}
		}
	}
	for (int i = 1; i <= roof; i++) {
		if (line[i] == 0) {
			q.push(i);
			res[i] = wait[i];
		}
	}
	for (int i = 1; i <= roof; i++) {
		q.push(i);
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now][i];
				line[next]--;
				res[next] = max(res[next], res[now] + wait[next]);
				if (line[next] == 0) q.push(next);
			}
		}
	}
	for (int i = 1; i <= roof; i++) {
		if (res_max < res[i]) res_max = res[i];
	}
	cout << res_max;
	return 0;
}