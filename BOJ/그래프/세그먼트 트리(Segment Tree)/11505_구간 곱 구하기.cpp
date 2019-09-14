#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
void update(int idx, long long val);
long long query(int L, int R, int Node_Num, int NodeL, int NodeR);
vector<long long> seg;
int n, k, m, h = 1;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	while (n > h) h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		long long num;
		scanf("%lld", &num);
		update(i, num % MOD);
	}
	int cnt = m + k;
	while (cnt--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			update(b, c);
		}
		else if (a == 2) {
			int b;
			int c;
			scanf("%d %d", &b, &c);
			printf("%lld\n", query(b, c, 1, 1, h));
		}
	}
	return 0;
}
void update(int idx, long long num) {
	idx += h - 1;
	seg[idx] = num;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = (seg[idx * 2] * seg[idx * 2 + 1]) % MOD;
	}
}
long long query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (NodeR < L || R < NodeL) return 1;
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return (query(L, R, NodeNum * 2, NodeL, mid) * query(L, R, NodeNum * 2 + 1, mid + 1, NodeR)) % MOD;
}