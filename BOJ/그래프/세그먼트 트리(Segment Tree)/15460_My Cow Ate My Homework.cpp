#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int n, h = 1;
double res;
int res_cnt;
vector<double> seg;
vector<double> seg_min;
void update(int idx, double val);
void update_min(int idx, double val);
double query(int L, int R, int NodeNum, int NodeL, int NodeR);
double query_min(int L, int R, int NodeNum, int NodeL, int NodeR);
double ans[100000];
int main(void) {
	scanf("%d", &n);
	while (n > h)h <<= 1;
	seg.resize(h * 2);
	seg_min.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		double num;
		scanf("%lf", &num);
		update(i, num);
		update_min(i, num);
	}
	for (int i = 1; i <= n - 2; i++) {
		res = max(res, (query(i + 1, n, 1, 1, h) - query_min(i + 1, n, 1, 1, h)) / (n - i - 1));
		ans[i] = (query(i + 1, n, 1, 1, h) - query_min(i + 1, n, 1, 1, h)) / (n - i - 1);
	}
	for (int i = 1; i <= n - 2; i++) {
		if (ans[i] == res) printf("%d\n", i);
	}
	return 0;
}
void update(int idx, double val) {
	idx += h - 1;
	seg[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg[idx] = seg[idx * 2] + seg[idx * 2 + 1];
	}
}
void update_min(int idx, double val) {
	idx += h - 1;
	seg_min[idx] = val;
	while (idx > 1) {
		idx /= 2;
		seg_min[idx] = min(seg_min[idx * 2], seg_min[idx * 2 + 1]);
	}
}
double query(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (L <= NodeL && NodeR <= R) return seg[NodeNum];
	else if (R < NodeL || NodeR < L) return 0;
	int mid = (NodeL + NodeR) / 2;
	return query(L, R, NodeNum * 2, NodeL, mid) + query(L, R, NodeNum * 2 + 1, mid + 1, NodeR);
}
double query_min(int L, int R, int NodeNum, int NodeL, int NodeR) {
	if (R < NodeL || NodeR < L) return LLONG_MAX;
	if (L <= NodeL && NodeR <= R) return seg_min[NodeNum];
	int mid = (NodeL + NodeR) / 2;
	return min(query_min(L, R, NodeNum * 2, NodeL, mid), query_min(L, R, NodeNum * 2 + 1, mid + 1, NodeR));
}