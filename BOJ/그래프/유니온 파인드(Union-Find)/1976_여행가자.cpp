#include <iostream>
#include <vector>
using namespace std;
int n, m;
void merge(int a, int b);
int find(int idx);
int par[201];
int main(void) {
	scanf("%d%d", &n, &m);
	fill(par, par + 201, -1);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			if (a == 1) merge(i, j);
		}
	}
	int pre = -1;
	int swc = 0;
	for (int i = 1; i <= m; i++) {
		int a;
		scanf("%d", &a);
		if (i == 1) pre = find(a);
		if (pre != find(a)) {
			swc++;
			break;
		}
	}
	if (!swc) printf("YES\n");
	else printf("NO\n");
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
}
int find(int idx) {
	if (par[idx] < 0) return idx;
	par[idx] = find(par[idx]);
	return par[idx];
}