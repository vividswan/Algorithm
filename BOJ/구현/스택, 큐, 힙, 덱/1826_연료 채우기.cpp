#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2000001;
int n,now,engine,ed,swc,cnt,les;
priority_queue<int, vector<int>> pq;
vector<int> adj[MAX];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int idx, val;
		scanf("%d%d", &idx, &val);
		adj[idx].push_back(val);
	}
	scanf("%d%d", &ed, &engine);
	while (1) {
		for (int i = now+1; i <= now + engine; i++) {
			if (i == ed) {
				swc++;
				break;
			}
			if (adj[i].size()) {
				for (int next : adj[i]) {
					pq.push(next);
				}
			}
		}
		if (swc) break;
		now = now + engine;
		if (pq.empty()) {
			les++;
			break;
		}
		cnt++;
		engine = pq.top();
		pq.pop();
	}
	if (!les) printf("%d\n", cnt);
	else printf("%d\n", -1);
	return 0;
}