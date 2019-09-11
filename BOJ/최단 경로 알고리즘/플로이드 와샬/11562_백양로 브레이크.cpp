#include <iostream>
#include <algorithm>
#define INF 12345678
using namespace std;
int arr[251][251], n, m, k;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		arr[a][b] = 0;
		if (c) arr[b][a] = 0;
		else arr[b][a] = 1;
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
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", arr[a][b]);
	}
}