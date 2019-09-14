#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> seg;
void update(int idx, int val);
int query(int L, int R, int NodeNum, int NodeL, int NodeR);
int n, h = 1;
int arr[100001];
int main(void) {
	scanf("%d", &n);
	while (n > h) h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int a = n - 1;
	int cnt = 1;
	update(arr[n], 1);
	while (a) {
		if (arr[a] > arr[a + 1]) break;
		else {
			update(arr[a], 1);
			cnt++;
			a--;
		}
	}
	int k = n - cnt;
	printf("%d\n", k);
	int go = 1;
	while (k) {
		printf("%d ", k - 1 + query(1, arr[go], 1, 1, h));
		update(arr[go], 1);
		k--;
		go++;
	}
}
void update(int idx, int val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
int query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	else if (R < NodeL || NodeR < L) return 0;
	int mid = (NodeL + NodeR) / 2;
	return query(L, R, NodeNum * 2, NodeL, mid) + query(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}