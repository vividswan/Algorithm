#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int par[1000001];
int find(int a) {
	if (par[a] < 0) return a;
	par[a] = find(par[a]);
	return par[a];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
}
int main(void) {
	scanf("%d%d", &n, &m);
	fill(par, par + 1000001, -1);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (a == 0) {
			merge(b, c);
		}
		else if (a == 1) {
			if (find(b) == find(c)) printf("YES\n");
			else printf("NO\n");
		}
	}
}