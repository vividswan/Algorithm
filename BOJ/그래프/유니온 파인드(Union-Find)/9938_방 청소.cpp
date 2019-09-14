#include <iostream>
using namespace std;
int n, l, par[300001], vis[300001];
void merge(int a, int b);
int find(int idx);
int main() {
	scanf("%d%d", &n, &l);
	fill(par, par + 300001, -1);
	for (int i = 1; i <= n; i++) {
		int a, b, swc = 0;
		scanf("%d%d", &a, &b);
		if (!vis[a]) {
			vis[a] = 1;
			merge(a, b);
		}
		else if (!vis[find(a)]) {
			vis[find(a)] = 1;
			merge(find(a), b);
		}
		else if (!vis[b]) {
			vis[b] = 1;
		}
		else if (!vis[find(b)]) {
			vis[find(b)] = 1;
		}
		else swc++;
		if (!swc) printf("LADICA\n");
		else printf("SMECE\n");
	}
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