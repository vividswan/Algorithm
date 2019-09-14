#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
vector<int> chk;
int n, l, r, x, max_go, res;
void dfs(int idx, int cnt);
void go(void);
int main(void) {
	scanf("%d%d%d%d", &n, &l, &r, &x);
	if (n == 1) {
		printf("%d\n", 0);
		return 0;
	}
	v.resize(n + 1);
	chk.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
	}
	for (max_go = 2; max_go <= n; max_go++) {
		dfs(1, 0);
	}
	printf("%d\n", res);
}
void dfs(int idx, int cnt) {
	if (cnt == max_go) {
		go();
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (chk[i]) continue;
		chk[i] = 1;
		dfs(i, cnt + 1);
		chk[i] = 0;
	}
}
void go(void) {
	int res_min = 1000001;
	int res_max = 0;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (chk[i]) {
			res_min = min(v[i], res_min);
			res_max = max(v[i], res_max);
			sum += v[i];
		}
	}
	if (sum >= l && sum <= r && res_max - res_min >= x) res++;
}