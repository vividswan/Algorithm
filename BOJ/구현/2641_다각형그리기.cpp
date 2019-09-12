#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, k;
queue<int>q;
vector<pair<int, int>> adj;
int arr[51];
int ans[101];
int go;
int task[101][51];
int map[201][201];
int vis[201][201];
int dx[] = { 0,0,-1,0,1 };
int dy[] = { 0,1,0,-1,0 };
int x = 100;
int y = 100;
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		q.push(arr[i]);
	}
	while (!q.empty()) {
		x += dx[q.front()];
		y += dy[q.front()];
		map[x][y] = 1;
		q.pop();
		adj.push_back({ x,y });
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &task[i][j]);
		}
		int swc = 0;
		for (int j = 0; j < adj.size(); j++) {
			int map_cnt = 0;
			memset(vis, 0, sizeof(vis));
			x = adj[j].first;
			y = adj[j].second;
			for (int a = 0; a < n; a++) {
				x += dx[task[i][a]];
				y += dy[task[i][a]];
				if (vis[x][y] == 0) {
					if (map[x][y] == 1) {
						vis[x][y] = 1;
						map_cnt++;
					}
				}
				if (map[x][y] == 0) break;
				if (a == n - 1) {
					if (map_cnt == n) {
						swc = 1;
						break;
					}
				}
			}
		}
		if (swc) {
			ans[i] = 1;
			go++;
		}
	}
	printf("%d\n", go);
	for (int i = 1; i <= k; i++) {
		if (ans[i]) {
			for (int l = 0; l < n; l++) printf("%d ", task[i][l]);
			printf("\n");
		}
	}
}