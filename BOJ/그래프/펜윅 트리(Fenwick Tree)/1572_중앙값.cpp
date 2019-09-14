#include <iostream>
#include <vector>
using namespace std;
int n, k;
long long res;
vector<long long> tree;
vector<long long> arr;
long long sum(int idx);
void update(int idx, long long val);
int main() {
	scanf("%d%d", &n, &k);
	tree.resize(65560);
	arr.resize(n + 1);
	for (int i = 1; i <= k - 1; i++) {
		scanf("%d", &arr[i]);
		update(arr[i] + 1, 1);
	}
	for (int i = k; i <= n; i++) {
		int left = 0;
		int right = 65560;
		scanf("%d", &arr[i]);
		update(arr[i] + 1, 1);
		while (left <= right) {
			int mid = (left + right) / 2;
			long long now = sum(mid);
			if (now >= ((k + 1) / 2)) right = mid - 1;
			else left = mid + 1;
		}
		update(arr[i - k + 1] + 1, -1);
		res += left - 1;
	}
	printf("%lld\n", res);
	return 0;
}
void update(int idx, long long val) {
	while (idx <= 65560) {
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