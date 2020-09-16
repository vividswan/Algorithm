#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;
int n, m;
vector<vector<pair<int,int>>> adj;
vector<bool> vis;
vector<int> dist;
int before;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int main(void) {
	cin >> n >> m;
	adj.resize(n + 1);
	vis.resize(n + 1);
	dist.resize(n + 1);
	fill(dist.begin(), dist.end(), INF);
	for (int i = 0; i < m; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		adj[st].push_back({ ed,val });
	}
	dist[1] = 0;
	pq.push({0,1});
	while (!pq.empty()) {
		int curr;
		do {
			curr = pq.top().second;
			pq.pop();
		} while (!pq.empty() && vis[curr]);
		if (vis[curr]) break;
		vis[curr] = true;
		for (int i = 0; i < adj[curr].size(); i++) {
			int next = adj[curr][i].first;
			int value = adj[curr][i].second;
			if (dist[next] > dist[curr] + value) {
				dist[next] = dist[curr] + value;
				pq.push({ dist[next],next });
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << i << " : ";
		if(dist[i]==INF) cout << "impossible" << '\n';
		else cout << dist[i] << '\n';
	}
}