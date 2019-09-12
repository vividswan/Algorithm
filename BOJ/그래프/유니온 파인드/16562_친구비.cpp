#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k, arr[10001], par[10001], res[10001];
int find(int idx);
void merge(int a, int b);
int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	fill(par, par + 10001, -1);
	fill(res, res + 10001, 987654321);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		res[find(i)] = min(res[find(i)], arr[i]);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (par[i] < 0) sum += res[i];
	}
	if (sum <= k) printf("%d\n", sum);
	else printf("Oh no");
}
int find(int idx) {
	if (par[idx] < 0) return idx;
	par[idx] = find(par[idx]);
	return par[idx];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
}