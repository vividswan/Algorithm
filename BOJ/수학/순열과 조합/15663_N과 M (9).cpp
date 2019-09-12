#include <iostream>
#include <algorithm>
using namespace std;
int n, m, check[9], res[9], swc[9];
void dfs(int idx, int cnt);
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &res[i]);
	}
	sort(res, res + n);
	dfs(0, 0);
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		int k = 0;
		for (int i = 0; i < n; i++) {
			if (check[i]) {
				printf("%d ", swc[k]);
				k++;
			}
		}
		printf("\n");
		return;
	}
	int roof[10001] = { 0, };
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		if (roof[res[i]]) continue;
		check[i] = 1;
		roof[res[i]] = 1;
		swc[cnt] = res[i];
		dfs(i, cnt + 1);
		check[i] = 0;
	}
}