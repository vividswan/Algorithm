#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> seg;
void update(int index, int val);
int lot[100001], h, roof;
int sum(int l, int r, int now, int now_l, int now_r);
int main(void) {
	scanf("%d", &roof);
	for (int i = 1; i <= roof; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		memset(lot, 0, sizeof(lot));
		h = 1;
		while (n + m > h) h *= 2;
		seg.clear();
		seg.resize(h * 2);
		for (int i = 1; i <= n; i++) {
			update(m + i, 1);
			lot[i] = m + i;
		}
		for (int i = 0; i < m; i++) {
			int a;
			scanf("%d", &a);
			printf("%d ", sum(1, lot[a] - 1, 1, 1, h));
			update(lot[a], 0);
			update(m - i, 1);
			lot[a] = m - i;
		}
		printf("\n");
	}
}
void update(int index, int val) {
	index += h - 1;
	seg[index] = val;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int sum(int l, int r, int now, int now_l, int now_r) {
	if (l <= now_l && now_r <= r) return seg[now];
	else if (now_r < l || r < now_l) return 0;
	int mid = (now_l + now_r) / 2;
	return sum(l, r, now * 2, now_l, mid) + sum(l, r, now * 2 + 1, mid + 1, now_r);
}