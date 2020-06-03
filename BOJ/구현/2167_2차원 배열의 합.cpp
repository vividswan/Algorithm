#include <iostream>
using namespace std;
int main(void) {
	int n, m;
	int arr[301][301];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int k;
	scanf("%d", &k);
	int total = 0;
	for (int l = 1; l <= k; l++) {
		int i, j, x, y;
		scanf("%d%d%d%d", &i, &j, &x, &y);
		for (int row = i; row <= x; row++) {
			for (int col = j; col <= y; col++) {
				total += arr[row][col];
			}
		}
		printf("%d\n", total);
		total = 0;
	}
	return 0;
}