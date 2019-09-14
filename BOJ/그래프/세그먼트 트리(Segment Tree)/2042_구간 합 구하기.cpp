#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
vector<long long> tree;
vector<long long> arr;
void update(int idx, long long val);
long long sum(int idx);
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	tree.resize(n + 1);
	arr.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		update(i, arr[i]);
	}
	int cnt = m + k;
	while (cnt--) {
		int a;
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long c;
			scanf("%d%lld", &b, &c);
			long long diff = c - arr[b];
			arr[b] = c;
			update(b, diff);
		}
		else {
			int b, c;
			scanf("%d%d", &b, &c);
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}
}
void update(int idx, long long val) {
	while (idx <= n) {
		tree[idx] += val;
		idx += (idx & -idx);
	}
}
long long sum(int idx) {
	long long res = 0;
	while (idx > 0) {
		res += tree[idx];
		idx -= (idx & -idx);
	}
	return res;
}