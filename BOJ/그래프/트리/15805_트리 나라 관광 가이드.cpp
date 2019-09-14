#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, vis[200001], root, pre, prenode[200001], max_num;
int main(void) {
	scanf("%d", &n);
	int swc = 0;
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		max_num = max(max_num, a);
		if (i == 1) {
			root = a;
			vis[a] = 1;
		}
		else {
			if (!vis[a]) {
				vis[a] = 1;
				prenode[a] = pre;
			}
		}
		pre = a;
	}
	max_num++;
	printf("%d\n", max_num);
	for (int i = 0; i < max_num; i++) {
		if (i == root) printf("%d ", -1);
		else printf("%d ", prenode[i]);
	}
}