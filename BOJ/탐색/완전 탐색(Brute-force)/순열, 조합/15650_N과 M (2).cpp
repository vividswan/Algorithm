#include <iostream>
using namespace std;
int n, m, check[9], res[9];
void dfs(int idx, int cnt);
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		res[i] = i + 1;
	}
	dfs(0, 0);
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < n; i++) {
			if (check[i]) {
				printf("%d ", res[i]);
			}
		}
		printf("\n");
		return;
	}
	for (int i = idx; i < n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		dfs(i, cnt + 1);
		check[i] = 0;
	}
}