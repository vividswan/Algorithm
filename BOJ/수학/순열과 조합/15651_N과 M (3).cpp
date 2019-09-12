#include <iostream>
using namespace std;
int n, m, check[9], res[9];
void dfs(int idx, int cnt);
int main(void) {
	scanf("%d %d", &n, &m);
	dfs(0, 0);
}
void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < cnt; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 0; i < n; i++) {
		res[cnt] = i + 1;
		dfs(i, cnt + 1);
	}
}