#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
int n, m, res;
int h = 1;
vector<int> seg;
vector<int> arr;
void update(int idx, int val);
void query(int NodeNum, int NodeL, int NodeR);
int main(void) {
	scanf("%d%d", &n, &m);
	while (n > h) h <<= 1;
	seg.resize(h * 2);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		update(i, a);
		arr[i] = a;
	}
	query(1, 1, h);
	int pre = -10;
	while (!pq.empty()) {
		int now = pq.top().first;
		if (now - 1 != pre) res++;
		pre = pq.top().second;
		pq.pop();
	}
	while (m--) {
		int a;
		scanf("%d", &a);
		if (a == 0) {
			printf("%d\n", res);
		}
		else if (a == 1) {
			int b;
			scanf("%d", &b);
			if (arr[b]) continue;
			else if (b == 1) {
				if (arr[2] == 0) res++;
				arr[1] = 1;
			}
			else if (b == n) {
				if (arr[n - 1] == 0) res++;
				arr[n] = 1;
			}
			else {
				arr[b] = 1;
				if (arr[b - 1] && arr[b + 1])res--;
				else if (arr[b - 1] || arr[b + 1]) continue;
				else res++;
			}
		}
	}
}
void update(int idx, int val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		if (seg[idx * 2] == 1 && seg[idx * 2 + 1] == 1) seg[idx] = 1;
		else if (seg[idx * 2] == 0 && seg[idx * 2 + 1] == 0) seg[idx] = 0;
		else seg[idx] = -1;
	}
}
void query(int NodeNum, int NodeL, int NodeR) {
	if (seg[NodeNum] == 0) return;
	if (seg[NodeNum] == 1) {
		pq.push({ NodeL,NodeR });
		return;
	}
	if (NodeL == NodeR) return;
	int mid = (NodeL + NodeR) / 2;
	query(NodeNum * 2, NodeL, mid);
	query(NodeNum * 2 + 1, mid + 1, NodeR);
	return;
}