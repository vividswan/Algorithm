#include <iostream>
#include <algorithm>
using namespace std;
int n, m, res[9], swc[9];
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
		for (int i = 0; i < cnt; i++) {
			printf("%d ", swc[i]);
		}
		printf("\n");
		return;
	}
	int roof[10001] = { 0, };
	for (int i = 0; i < n; i++) {
		if (roof[res[i]]) continue;
		roof[res[i]] = 1;
		swc[cnt] = res[i];
		dfs(i, cnt + 1);
	}
}