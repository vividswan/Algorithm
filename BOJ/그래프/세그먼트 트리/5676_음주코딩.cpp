#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int query(int L, int R, int NodeNum, int NodeL, int NodeR);
vector<int> seg;
int n, k, h = 1;
void update(int idx, int val);
int main(void) {
	while (scanf("%d%d", &n, &k) != EOF) {
		queue<char> q;
		h = 1;
		while (n > h) h <<= 1;
		seg.clear();
		seg.resize(h * 2);
		for (int i = 1; i <= n; i++) {
			int a;
			scanf("%d", &a);
			update(i, a);
		}
		while (k--) {
			char a;
			int b, c;
			scanf(" %c", &a);
			scanf("%d%d", &b, &c);
			if (a == 'C') update(b, c);
			else {
				int res = query(b, c, 1, 1, h);
				if (res > 0) q.push('+');
				else if (res == 0) q.push('0');
				else q.push('-');
			}
		}
		while (!q.empty()) {
			printf("%c", q.front());
			q.pop();
		}
		printf("\n");
	}
}
void update(int idx, int val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		if (seg[idx * 2] == 0 || seg[idx * 2 + 1] == 0) {
			seg[idx] = 0;
		}
		else if ((seg[idx * 2] > 0 && seg[idx * 2 + 1] > 0) || (seg[idx * 2] < 0 && seg[idx * 2 + 1] < 0)) {
			seg[idx] = 1;
		}
		else seg[idx] = -1;
	}
}
int query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (R < NodeL || NodeR < L) return 1;
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return query(L, R, NodeNum * 2, NodeL, mid) * query(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}