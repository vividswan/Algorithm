#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int n, m, h = 1;
vector<long long> seg_max;
vector<long long> seg_min;
void update_max(int idx, long long val);
void update_min(int idx, long long val);
long long query_max(int L, int R, int NodeNum, int NodeL, int NodeR);
long long query_min(int L, int R, int NodeNum, int NodeL, int NodeR);
int main(void) {
	scanf("%d %d", &n, &m);
	while (n > h)h <<= 1;
	seg_max.resize(h * 2);
	seg_min.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		long long num;
		scanf("%lld", &num);
		update_max(i, num);
		update_min(i, num);
	}
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%lld %lld\n", query_min(min(a, b), max(a, b), 1, 1, h), query_max(min(a, b), max(a, b), 1, 1, h));
	}
}
void update_max(int idx, long long val) {
	idx += h - 1;
	seg_max[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg_max[idx] = max(seg_max[idx * 2], seg_max[idx * 2 + 1]);
	}
}
void update_min(int idx, long long val) {
	idx += h - 1;
	seg_min[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg_min[idx] = min(seg_min[idx * 2], seg_min[idx * 2 + 1]);
	}
}
long long query_max(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (R < NodeL || NodeR < L) return -1;
	if (L <= NodeL && NodeR <= R) return seg_max[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return max(query_max(L, R, NodeNum * 2, NodeL, mid), query_max(L, R, NodeNum * 2 + 1, mid + 1, NodeR));
}
long long query_min(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (R < NodeL || NodeR < L) return LLONG_MAX;
	if (L <= NodeL && NodeR <= R) return seg_min[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return min(query_min(L, R, NodeNum * 2, NodeL, mid), query_min(L, R, NodeNum * 2 + 1, mid + 1, NodeR));
}