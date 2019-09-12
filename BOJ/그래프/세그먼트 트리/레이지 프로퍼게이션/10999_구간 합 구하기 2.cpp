#include <iostream>
#include <vector>
using namespace std;
int n, m, k, h = 1;
vector<long long> seg;
vector<long long> lazy;
void update(int idx, long long val);
void query_lazy(int L, int R, int Node_Num, int NodeL, int NodeR, long long val);
long long query_sum(int L, int R, int Node_Num, int NodeL, int NodeR);
void propagation(int Node_Num, int NodeL, int NodeR);
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	while (n > h) h <<= 1;
	lazy.resize(h * 2);
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		long long num;
		scanf("%lld", &num);
		update(i, num);
	}
	for (int i = 1; i <= m + k; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b, c;
			long long d;
			scanf("%d%d%lld", &b, &c, &d);
			query_lazy(b, c, 1, 1, h, d);
		}
		else if (a == 2) {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", query_sum(b, c, 1, 1, h));
		}
	}
	return 0;
}
void update(int idx, long long val) {
	idx += h - 1;
	seg[idx] += val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
void query_lazy(int L, int R, int Node_Num, int NodeL, int NodeR, long long val) {
	propagation(Node_Num, NodeL, NodeR);
	if (NodeR < L || R < NodeL) return;
	if (L <= NodeL && NodeR <= R) {
		seg[Node_Num] += val * (NodeR - NodeL + 1);
		if (NodeL != NodeR) {
			lazy[Node_Num * 2] += val;
			lazy[Node_Num * 2 + 1] += val;
		}
		return;
	}
	int mid = (NodeL + NodeR) / 2;
	query_lazy(L, R, Node_Num * 2, NodeL, mid, val);
	query_lazy(L, R, Node_Num * 2 + 1, mid + 1, NodeR, val);
	seg[Node_Num] = seg[Node_Num * 2] + seg[Node_Num * 2 + 1];
}
void propagation(int Node_Num, int NodeL, int NodeR) {
	if (lazy[Node_Num] == 0)return;
	seg[Node_Num] += lazy[Node_Num] * (NodeR - NodeL + 1);
	if (NodeR != NodeL) {
		lazy[Node_Num * 2] += lazy[Node_Num];
		lazy[Node_Num * 2 + 1] += lazy[Node_Num];
	}
	lazy[Node_Num] = 0;
}
long long query_sum(int L, int R, int Node_Num, int NodeL, int NodeR) {
	propagation(Node_Num, NodeL, NodeR);
	if (R < NodeL || NodeR < L) return 0;
	if (L <= NodeL && NodeR <= R) return seg[Node_Num];
	int mid = (NodeL + NodeR) / 2;
	return query_sum(L, R, Node_Num * 2, NodeL, mid) + query_sum(L, R, Node_Num * 2 + 1, mid + 1, NodeR);
}