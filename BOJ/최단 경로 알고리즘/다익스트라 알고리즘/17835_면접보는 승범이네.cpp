#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;
long long n, m, k;
long long dist[100010];
vector<pair<long long, long long>> adj[100010];
long long maxx;
long long ans;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;
void dijikstra() {
	while (!pq.empty()) {
		long long cost = pq.top().first;
		long long idx = pq.top().second;
		pq.pop();
		if (cost > dist[idx]) continue;
		for (int i = 0; i < adj[idx].size(); i++) {
			long long next = adj[idx][i].first;
			long long nextCost = adj[idx][i].second;
			if (dist[next] > dist[idx] + nextCost) {
				dist[next] = dist[idx] + nextCost;
				pq.push({ dist[next],next });
			}
		}
	}
}
int main(void) {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		long long u, v;
		long long c;
		scanf("%lld%lld%lld", &u, &v, &c);
		adj[v].push_back({ u,c });
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
	}
	for (int i = 1; i <= k; i++) {
		long long st;
		scanf("%lld", &st);
		dist[st] = 0;
		pq.push({ 0,st });
	}
	dijikstra();
	for (int i = 1; i <= n; i++) {
		if (maxx < dist[i] && dist[i] != LLONG_MAX) {
			ans = i;
			maxx = dist[i];
		}
	}
	printf("%lld\n%lld\n", ans, maxx);
	return 0;
}