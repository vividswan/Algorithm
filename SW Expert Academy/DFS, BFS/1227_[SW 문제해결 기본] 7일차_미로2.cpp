#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int main(void) {
	for (int i = 1; i <= 10; i++) {
		int test_num;
		scanf("%d", &test_num);
		int map[101][101];
		pair<int, int> st;
		pair<int, int> ed;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 2) {
					st.first = i;
					st.second = j;
				}
				if (map[i][j] == 3) {
					ed.first = i;
					ed.second = j;
					map[i][j] = 0;
				}
			}
		}
		queue<pair<int, int>> q;
		q.push({ st.first,st.second });
		int vis[101][101];
		memset(vis, -1, sizeof(vis));
		vis[st.first][st.second] = 1;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx > 99 || ny > 99 || nx < 0 || ny <  0) continue;
				if (map[nx][ny] == 1) continue;
				if (vis[nx][ny] == -1) {
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
		}
		int res;
		if (vis[ed.first][ed.second] == -1) res = 0;
		else res = 1;
		printf("#%d %d\n", test_num, res);
	}
	return 0;
}