#include <iostream>
using namespace std;
int n, m, map[51][51];
int sum = 1;
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; 1; k++) {
				if (i + k <= n && j + k <= m && map[i][j] == map[i][j + k] && map[i][j] == map[i + k][j] && map[i][j] == map[i + k][j + k]) {
					int size = (k + 1) * (k + 1);
					if (size > sum) sum = size;
				}
				if (i + k > n || j + k > m) break;
			}
		}
	}
	printf("%d\n", sum);
}