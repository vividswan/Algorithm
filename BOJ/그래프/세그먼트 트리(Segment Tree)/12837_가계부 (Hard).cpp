#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> seg;
int n, q, h = 1;
void update(int idx, long long val);
long long query(int L, int R, int NodeNum, int NodeL, int NodeR);
int main() {
	scanf("%d%d", &n, &q);
	while (n > h) h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= q; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int p;
			long long x;
			scanf("%d%lld", &a, &p);
			update(a, p);
		}
		else {
			int p, q;
			scanf("%d%d", &p, &q);
			printf("%lld\n", query(p, q, 1, 1, h));
		}
	}
}
void update(int idx, long long val) {
	idx += h - 1;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
long long query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (NodeR < L || R < NodeL) return 0;
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return query(L, R, NodeNum * 2, NodeL, mid) + query(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}