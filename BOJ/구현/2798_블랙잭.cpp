#include <iostream>
using namespace std;
int ox(int a, int b);
int check[101];
void go(int index, int cnt, int sum);
int res = 100001;
int ans = 0;
int n, m, arr[101];
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	go(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
void go(int index, int cnt, int sum) {
	if (index >= n + 1) return;
	if (sum > m) return;
	if (cnt == 3) {
		if (sum <= m) {
			int r = m - sum;
			if (res > r) {
				res = r;
				ans = sum;
			}
			return;
		}
	}
	go(index + 1, cnt + 1, sum + arr[index + 1]);
	go(index + 1, cnt, sum);
}