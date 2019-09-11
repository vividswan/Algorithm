#include <iostream>
#include <vector>
using namespace std;
int n, m, h = 1;
vector<int> seg;
vector<int> lazy;
void query_lazy(int L, int R, int NodeNum, int NodeL, int NodeR);
void propagation(int NodeNum, int NodeL, int NodeR);
int query_sum(int L, int R, int NodeNum, int NodeL, int NodeR);
int main(void) {
	scanf("%d%d", &n, &m);
	while (n > h)h <<= 1;
	seg.resize(h * 2);
	lazy.resize(h * 2);
	while (m--) {
		int o, s, t;
		scanf("%d%d%d", &o, &s, &t);
		if (!o) query_lazy(s, t, 1, 1, h);
		else printf("%d\n", query_sum(s, t, 1, 1, h));
	}
}
int query_sum(int L, int R, int NodeNum, int NodeL, int NodeR) {
	propagation(NodeNum, NodeL, NodeR);
	if (R < NodeL || NodeR < L) return 0;
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return query_sum(L, R, NodeNum * 2, NodeL, mid) + query_sum(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}
void propagation(int NodeNum, int NodeL, int NodeR) {
	if (!lazy[NodeNum]) return;
	seg[NodeNum] = (NodeR - NodeL + 1) - seg[NodeNum];
	if (NodeL != NodeR) {
		lazy[NodeNum * 2] ^= 1;
		lazy[NodeNum * 2 + 1] ^= 1;
	}
	lazy[NodeNum] = 0;
}
void query_lazy(int L, int R, int NodeNum, int NodeL, int NodeR) {
	propagation(NodeNum, NodeL, NodeR);
	if (R < NodeL || NodeR < L) return;
	if (L <= NodeL && NodeR <= R) {
		seg[NodeNum] = (NodeR - NodeL + 1) - seg[NodeNum];
		if (NodeL != NodeR) {
			lazy[NodeNum * 2] ^= 1;
			lazy[NodeNum * 2 + 1] ^= 1;
		}
		return;
	}
	int mid = (NodeL + NodeR) / 2;
	query_lazy(L, R, NodeNum * 2, NodeL, mid);
	query_lazy(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
	seg[NodeNum] = seg[NodeNum * 2] + seg[NodeNum * 2 + 1];
}