#include <iostream>
#include <vector>
using namespace std;
int n, m;
long long tree[1025][1025];
long long val[1025][1025];
void update(int x, int y, long long val);
long long sum(int x, int y);
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &val[i][j]);
			update(i, j, val[i][j]);
		}
	}
	while (m--) {
		int w;
		scanf("%d", &w);
		if (!w) {
			int x, y;
			long long c;
			scanf("%d%d%lld", &x, &y, &c);
			long long diff = c - val[x][y];
			val[x][y] = c;
			update(x, y, diff);
		}
		else {
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			printf("%lld\n", sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1));
		}
	}
}
void update(int x, int y, long long val) {
	for (int i = x; i <= n; i += (i & -i)) {
		for (int j = y; j <= n; j += (j & -j)) {
			tree[i][j] += val;
		}
	}
}
long long sum(int x, int y) {
	long long res = 0;
	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) {
			res += tree[i][j];
		}
	}
	return res;
}
