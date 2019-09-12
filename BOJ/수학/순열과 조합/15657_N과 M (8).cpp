#include <iostream>
#include <algorithm>
using namespace std;
int n, m, check[9], res[9], swc[9];
void dfs(int idx, int cnt);
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &res[i]);
	}
	sort(res, res + n);
	dfs(0, 0);
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		int k = 0;
		for (int i = 0; i < cnt; i++) {
			printf("%d ", swc[k]);
			k++;
		}
		printf("\n");
		return;
	}
	for (int i = idx; i < n; i++) {
		swc[cnt] = res[i];
		dfs(i, cnt + 1);
	}
}