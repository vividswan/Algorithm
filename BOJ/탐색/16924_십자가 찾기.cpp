#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;
map<int, int> check_map;
queue<pair<pair<int, int>, int>> q;
int n, m, check[10001], tot, tot_cnt;
char char_map[101][101];
void go(int i, int j);
int vis[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &char_map[i][j]);
			if (char_map[i][j] == '*') tot++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (char_map[i][j] == '*') go(i, j);
		}
	}
	if (tot_cnt != tot) printf("-1\n");
	else {
		printf("%d\n", q.size());
		while (!q.empty()) {
			printf("%d %d %d\n", q.front().first.first, q.front().first.second, q.front().second);
			q.pop();
		}
	}
}
void go(int i, int j) {
	int res = 0;
	int cnt = 0;
	int l = 1;
	for (l;; l++) {
		for (int k = 0; k < 4; k++) {
			int nx = i + l * dx[k];
			int ny = j + l * dy[k];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m || char_map[nx][ny] == '.') continue;
			cnt++;
		}
		if (cnt == 4) {
			cnt = 0;
			res++;
			continue;
		}
		else {
			l--;
			break;
		}
	}
	if (res) {
		if (!vis[i][j]) {
			tot_cnt++;
			vis[i][j]++;
		}
		for (int s = 1; s <= l; s++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + s * dx[k];
				int ny = j + s * dy[k];
				if (!vis[nx][ny]) {
					tot_cnt++;
					vis[nx][ny]++;
				}
			}
		}
		q.push({ {i,j},l });
		return;
	}
	else return;
}