#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <algorithm>
typedef long long ll;
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, arr[1000002], h = 1;
ll res;
void update(int index, ll val);
vector<ll> seg;
ll query(int nodeL, int nodeR, int node, int L, int R);
int main(void) {
	scanf("%d", &n);
	while (n > h) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		arr[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		pq.push({ arr[x],i });
	}
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		res += query(1, h, 1, p.second + 1, h);
		update(p.second, 1);
	}
	printf("%lld\n", res);
}
void update(int index, ll val) {
	index += h - 1;
	seg[index] = val;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
ll query(int nodeL, int nodeR, int node, int L, int R) {
	if (L <= nodeL && nodeR <= R) return seg[node];
	else if (nodeR < L || R < nodeL) return 0;
	int mid = (nodeL + nodeR) / 2;
	return query(nodeL, mid, node * 2, L, R) + query(mid + 1, nodeR, node * 2 + 1, L, R);
}