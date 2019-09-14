#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int arr[500001];
priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int query(int L, int R, int NodeNum, int NodeL, int NodeR);
int n, h = 1;
vector<int> seg;
void update(int idx, int val);
int main(void) {
	scanf("%d", &n);
	while (n > h) h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		pq.push({ a,i });
	}
	int cnt = 1;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		arr[p.second] = cnt;
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", query(arr[i], h, 1, 1, h) + 1);
		update(arr[i], 1);
	}
}
void update(int idx, int val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
int query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	else if (R < NodeL || NodeR < L) return 0;
	int mid = (NodeL + NodeR) / 2;
	return query(L, R, NodeNum * 2, NodeL, mid) + query(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}