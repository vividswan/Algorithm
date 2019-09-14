#include <iostream>
#include <vector>
using namespace std;
int t, pre[1001], in[1001], in_idx[1001];
void query(int pre_st, int pre_ed, int in_st, int in_ed);
int main(void) {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
		for (int i = 1; i <= n; i++) scanf("%d", &in[i]);
		for (int i = 1; i <= n; i++) in_idx[in[i]] = i;
		query(1, n, 1, n);
		printf("\n");
	}
}
void query(int pre_st, int pre_ed, int in_st, int in_ed) {
	if (pre_st > pre_ed || in_st > in_ed) return;
	int root = pre[pre_st];
	int idx = in_idx[root];
	int cnt = idx - in_st;
	query(pre_st + 1, pre_st + cnt, in_st, idx - 1);
	query(pre_st + cnt + 1, pre_ed, idx + 1, in_ed);
	printf("%d ", root);
}