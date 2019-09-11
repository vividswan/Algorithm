#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n, arr[21][21], cnt, res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			scanf("%d", &a);
			arr[i][j] = a;
			if (a) cnt++;
		}
	}
	queue<pair<int, int>> q;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == j) continue;
				if (k == i) continue;
				if (k == j) continue;
				if (arr[i][j] == arr[i][k] + arr[k][j]) {
					q.push({ i,j });
				}
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	while (!q.empty()) {
		arr[q.front().first][q.front().second] = -1;
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == -1) continue;
			res += arr[i][j];
		}
	}
	printf("%d\n", res / 2);
}