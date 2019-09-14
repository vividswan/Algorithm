#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int roof, line[123457], vis[123457];
long long pm[123457], res;
vector<int> adj[123457];
queue<int> q;
int main(void) {
	scanf("%d", &roof);
	for (int i = 2; i <= roof; i++) {
		char t;
		long long a;
		int p;
		scanf(" %c%lld%d", &t, &a, &p);
		if (t == 'S') pm[i] = a;
		else if (t == 'W') pm[i] = -a;
		adj[i].push_back(p);
		line[p]++;
	}
	for (int i = 1; i <= roof; i++) {
		if (line[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			if (pm[now] >= 0) pm[next] += pm[now];
			line[next]--;
			if (line[next] == 0) q.push(next);
		}
	}
	printf("%lld\n", pm[1]);
	return 0;
}