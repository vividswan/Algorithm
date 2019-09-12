#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int v, e, vis[10001];
long long res;
priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> pq;
vector<vector<pair<int, long long>>> adj;
void prim(int idx);
int main(void) {
	scanf("%d%d", &v, &e);
	adj.resize(v + 1);
	for (int i = 1; i <= e; i++) {
		int a, b;
		long long c;
		scanf("%d%d%lld", &a, &b, &c);
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int now = pq.top().second;
		if (!vis[now])res += pq.top().first;
		vis[now] = 1;
		pq.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i].first;
			if (!vis[next]) {
				pq.push({ adj[now][i].second,next });
			}
		}
	}
	printf("%lld\n", res);
}
