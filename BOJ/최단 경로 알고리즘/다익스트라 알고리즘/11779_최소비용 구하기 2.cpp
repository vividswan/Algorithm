#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#define INF 98765432
using namespace std;
int lot[1001], n, m, dist[1001], vis[1001], pre[1001];
vector<pair <int, int>> adj[1001];
int main(void) {
	fill(dist, dist + 1001, INF);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(make_pair(b, c));
	}
	int st, go;
	cin >> st >> go;
	dist[st] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, st));
	while (!pq.empty()) {
		int now;
		do {
			now = pq.top().second;
			pq.pop();
		} while (!pq.empty() && vis[now]);
		if (vis[now]) break;
		vis[now]++;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			int d = adj[now][i].second;
			if (dist[next] > d + dist[now]) {
				dist[next] = d + dist[now];
				pre[next] = now;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
	int fin = pre[go];
	stack<int>s;
	while (1) {
		if (fin == st) break;
		s.push(fin);
		fin = pre[fin];
	}
	cout << dist[go] << "\n" << 2 + s.size() << "\n" << st << ' ';
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << go;
}