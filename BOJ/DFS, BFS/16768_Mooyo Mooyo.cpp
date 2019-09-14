#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n, k;
int arr[102][12];
int vis[102][12];
int chk[102][12];
int swc;
int go_k;
int go_swc;
void bfs(int i, int j);
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	while (1) {
		go_swc = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 10; j++) {
				if (!vis[i][j] && arr[i][j]) {
					vis[i][j] = 1;
					bfs(i, j);
					go_k = 0;
				}
			}
		}
		for (int j = 1; j <= 10; j++) {
			queue<int> q;
			for (int i = n; i >= 1; i--) {
				if (arr[i][j]) {
					q.push(arr[i][j]);
					arr[i][j] = 0;
				}
			}
			int len = q.size();
			for (int i = n; i > n - len; i--) {
				arr[i][j] = q.front();
				q.pop();
			}
		}
		if (go_swc == 0) break;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 10; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
void bfs(int i, int j) {
	memset(chk, 0, sizeof(chk));
	int cnt = 1;
	queue<pair<int, int>> q;
	q.push({ i,j });
	chk[i][j] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny<1 || nx>n || ny>10) continue;
			if (vis[nx][ny]) continue;
			if (arr[x][y] == arr[nx][ny]) {
				vis[nx][ny] = 1;
				cnt++;
				q.push({ nx,ny });
				chk[nx][ny] = 1;
			}
		}
	}
	if (cnt >= k) {
		go_swc = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= 10; j++) {
				if (chk[i][j]) arr[i][j] = 0;
			}
		}
	}
}