#include <iostream>
using namespace std;
int map[401][401];
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		map[a][b] = -1;
		map[b][a] = 1;
	}
	for (int v = 1; v <= n; v++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][v] == -1 && map[v][j] == -1) {
					map[i][j] = -1;
					map[j][i] = 1;
				}
			}
		}
	}
	int res;
	scanf("%d", &res);
	for (int i = 0; i < res; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", map[a][b]);
	}
}