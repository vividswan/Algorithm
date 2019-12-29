#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int vis[30];
int x, n;
map<char, int> m;
priority_queue<pair<int,char>, vector<pair<int,char>>> pq;
int main(void) {
	scanf("%d%d", &x, &n);
	int lim = x / 20;
	for (int i = 1; i <= n; i++) {
		char now;
		scanf(" %c ", &now);
		int val;
		scanf("%d", &val);
		if (val < lim) continue;
		vis[now - 'A'] = 1;
		for (int i = 1; i <= 14; i++) {
			pq.push({ val / i,now });
		}
	}
	if (pq.empty()) return 0;
	for (int i = 1; i <= 14; i++) {
		m[pq.top().second] += 1;
		pq.pop();
	}
	for (int i = 'A'; i <= 'Z'; i++) {
		if (vis[i - 'A']) {
			if (m[i]) printf("%c %d\n", i, m[i]);
			else printf("%c %d\n", i, 0);
		}
	}
	return 0;
}