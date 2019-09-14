#include <iostream>
using namespace std;
int arr[201][4], n;
int vis[101], sum[201];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	for (int i = 1; i <= 3; i++) {
		fill(vis, vis + 101, 0);
		for (int j = 1; j <= n; j++) {
			vis[arr[j][i]]++;
		}
		for (int j = 1; j <= n; j++) {
			if (vis[arr[j][i]] == 1) sum[j] += arr[j][i];
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", sum[i]);
	}
}