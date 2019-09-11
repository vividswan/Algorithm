#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int l;
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { -2,-1,1,2,-2,-1,1,2 };
pair<int, int> ed;
pair<int, int> st;
queue<pair<int, int>> q;
int vis[301][301];
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &l);
		scanf("%d%d", &st.first, &st.second);
		scanf("%d%d", &ed.first, &ed.second);
		vis[st.first][st.second] = 1;
		q.push({ st.first,st.second });
		while (!q.empty()) {
			auto p = q.front();
			q.pop();
			for (int i = 0; i < 8; i++) {
				int nx = p.first + dx[i];
				int ny = p.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= l || ny >= l) continue;
				if (vis[nx][ny]) continue;
				vis[nx][ny] = vis[p.first][p.second] + 1;
				q.push({ nx,ny });
			}
		}
		printf("%d\n", vis[ed.first][ed.second] - 1);
	}
	return 0;
}