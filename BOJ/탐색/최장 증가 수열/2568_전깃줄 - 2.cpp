#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
priority_queue<int, vector<int>, greater<>> chk_q;
vector<int> v;
pair<int, int> p[500001];
int chk[500001];
int n, res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		pq.push({ b,a });
		chk_q.push(a);
	}
	v.push_back(-1);
	int go = 0;
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		if (now > v.back()) {
			v.push_back(now);
			res++;
			p[go] = { res,now };
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), now) - v.begin();
			v[idx] = now;
			p[go] = { idx,now };
		}
		go++;
	}
	int key = res;
	for (int i = n - 1; i >= 0; i--) {
		if (key == p[i].first) {
			chk[p[i].second] = 1;
			key--;
			if (key == 0) break;
		}
	}
	printf("%d\n", n - res);
	while (!chk_q.empty()) {
		int now = chk_q.top();
		chk_q.pop();
		if (chk[now]) continue;
		else printf("%d\n", now);
	}
}