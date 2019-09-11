#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, h = 1;
vector<long long> seg;
void update(int index, long long val);
int find(long long num, int now, int now_l, int now_r);
int main(void) {
	scanf("%d", &n);
	while (1000000 > h) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			long long x;
			scanf("%lld", &x);
			int d = find(x, 1, 1, h);
			update(d, -1);
			printf("%d\n", d);
		}
		else if (a == 2) {
			int b;
			long long c;
			scanf("%d %lld", &b, &c);
			update(b, c);
		}
	}
}
void update(int index, long long val) {
	index += h - 1;
	seg[index] += val;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
	return;
}
int find(long long num, int now, int now_l, int now_r) {
	if (now * 2 - h + 1 > 1000000) return now - h + 1;
	int mid = (now_l + now_r) / 2;
	if (num <= seg[now * 2]) {
		return find(num, now * 2, now_l, mid);
	}
	else {
		return find(num - seg[now * 2], now * 2 + 1, mid + 1, now_r);
	}
}