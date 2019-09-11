#include <iostream>
#include <vector>
using namespace std;
int n, arr[100001], h = 1;
vector<long long> seg;
long long query(int L, int R, int Node_Num, int NodeL, int NodeR);
void update(int idx, long long val);
int main(void) {
	scanf("%d", &n);
	while (n > h) h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		arr[a] = i;
		update(i, 1);
	}
	int st = 1;
	int ed = n;
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			int go = arr[st];
			printf("%lld\n", query(1, go - 1, 1, 1, h));
			update(go, 0);
			st++;
		}
		else {
			int go = arr[ed];
			printf("%lld\n", query(go + 1, h, 1, 1, h));
			update(go, 0);
			ed--;
		}
	}
	return 0;
}
long long query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	else if (R < NodeL || NodeR < L) return 0;
	int mid = (NodeL + NodeR) / 2;
	return query(L, R, NodeNum * 2, NodeL, mid) + query(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}
void update(int idx, long long val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}