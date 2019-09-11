#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int inf = 1000000000;
int n, m, map[101][101], path[101][101];
queue<int> q;
vector<int> temp;
void ans(int st, int ed);
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
				if (map[i][v] + map[v][j] < map[i][j]) {
					map[i][j] = map[i][v] + map[v][j];
					path[i][j] = v;
				}
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] >= 1000000000 || i == j) printf("0\n");
			else {
				ans(i, j);
				printf("%d ", 2 + q.size());
				printf("%d ", i);
				while (!q.empty()) {
					int now = q.front();
					q.pop();
					printf("%d ", now);
				}
				printf("%d\n", j);
			}
		}
	}
}
void ans(int st, int ed) {
	if (path[st][ed]) {
		ans(st, path[st][ed]);
		q.push(path[st][ed]);
		ans(path[st][ed], ed);
	}
}