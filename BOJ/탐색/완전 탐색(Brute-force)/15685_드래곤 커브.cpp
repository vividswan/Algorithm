#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
int map[101][101];
void func(int, int, int, int);
int main(void) {
	int cnt = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y, d, g;
		scanf("%d%d%d%d", &x, &y, &d, &g);
		func(y, x, d, g);
	}
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
void func(int y, int x, int d, int g) {
	int now_g = 1;
	vector<int> adj;
	map[y][x] = 1;
	x += dx[d];
	y += dy[d];
	map[y][x] = 1;
	adj.push_back(d);
	while (now_g <= g) {
		int val = adj.size();
		queue<int> q;
		for (int i = 0; i < val; i++) {
			int siz = (adj[val -1 - i] + 1) % 4;
			adj.push_back(siz);
			q.push(siz);
		}
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			x += dx[now];
			y += dy[now];
			map[y][x] = 1;
		}
		now_g++;
	}
	return;
}