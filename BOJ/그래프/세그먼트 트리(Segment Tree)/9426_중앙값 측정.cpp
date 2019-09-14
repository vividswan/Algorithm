#include <iostream>
#include <vector>
#define MAX_TEM 65566
using namespace std;
vector<long long> seg;
vector<long long> idx;
long long query(long long val, long long NodeNum, long long NodeL, long long NodeR);
long long n, k, h = 1;
long long ans;
void update(long long num, long long val);
int main() {
	scanf("%lld%lld", &n, &k);
	while (MAX_TEM > h) h <<= 2;
	seg.resize(h * 2);
	idx.resize(n + 1);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &idx[i]);
	}
	for (int i = 0; i < k - 1; i++)
		update(idx[i], 1);
	for (int i = k - 1; i < n; i++) {
		update(idx[i], 1);
		ans += query((k + 1) / 2, 1, 0, h - 1);
		update(idx[i - k + 1], -1);
	}
	printf("%lld\n", ans);
	return 0;
}
void update(long long num, long long val) {
	num += h;
	seg[num] += val;
	while (num > 1) {
		num /= 2;
		seg[num] = seg[num * 2] + seg[num * 2 + 1];
	}
}
long long query(long long val, long long NodeNum, long long NodeL, long long NodeR) {
	long long mid = (NodeL + NodeR) / 2;
	if (NodeL == NodeR) return NodeL;
	if (seg[NodeNum * 2] >= val) return query(val, NodeNum * 2, NodeL, mid);
	return query(val - seg[NodeNum * 2], NodeNum * 2 + 1, mid + 1, NodeR);
}