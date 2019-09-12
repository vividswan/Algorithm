#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		queue<pair<int, int>> q;
		priority_queue<int, vector<int>> pq;
		int n, m, ans;
		int cnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			int val;
			scanf("%d", &val);
			pq.push(val);
			q.push({ i,val });
		}
		while (!q.empty()) {
			int now = q.front().first;
			int now_val = q.front().second;
			q.pop();
			if (now_val == pq.top()) {
				cnt++;
				if (now == m) {
					ans = cnt;
					break;
				}
				pq.pop();
			}
			else {
				q.push({ now,now_val });
			}
		}
		printf("%d\n", ans);
	}
}