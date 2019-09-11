#include <iostream>
using namespace std;
int inf = 1000000000;
int n, m, map[101][101];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)map[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (map[a][b] > c) {
			map[a][b] = c;
		}
	}
	for (int v = 1; v <= n; v++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][v] + map[v][j] < map[i][j]) map[i][j] = map[i][v] + map[v][j];
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] >= 1000000000) printf("0 ");
			else printf("%d ", map[i][j]);
		}
		printf("\n");
	}
}