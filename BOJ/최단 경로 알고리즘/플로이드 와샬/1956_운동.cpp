#include <iostream>
#include <algorithm>
#define INF 12345678
using namespace std;
int arr[401][401], n, m, res;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr[a][b] = c;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	res = INF;
	for (int i = 1; i < n; i++) {
		res = min(res, arr[i][i]);
	}
	if (res < INF) printf("%d\n", res);
	else printf("-1\n");
}