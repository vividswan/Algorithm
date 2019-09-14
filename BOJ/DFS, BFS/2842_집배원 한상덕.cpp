#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n;
int high[51][51];
pair<int, int> st;
vector<pair<int, int>> obj;
vector<int> v;
int vis[51][51];
int le;
int ri;
int mid;
int res;
int chk(int val);
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int bfs(int st_x, int st_y, int val, int st_val);
int main(void) {
	scanf("%d", &n);
	v.resize(n * n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char a;
			scanf(" %c", &a);
			if (a == 'K') {
				obj.push_back({ i,j });
			}
			else if (a == 'P') {
				st.first = i;
				st.second = j;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &high[i][j]);
			v[cnt] = high[i][j];
			cnt++;
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	ri = v[v.size() - 1];
	while (le <= ri) {
		mid = (le + ri) / 2;
		if (chk(mid)) {
			ri = mid - 1;
			res = mid;
		}
		else le = mid + 1;
	}
	printf("%d\n", res);
	return 0;
}

int chk(int val) {
	for (int i = 0; i < v.size(); i++) {
		if (high[st.first][st.second] < v[i]) return 0;
		if (high[st.first][st.second] > v[i] + val) continue;
		memset(vis, 0, sizeof(vis));
		if (bfs(st.first, st.second, val, v[i])) return 1;
	}
	return 0;
}
int bfs(int st_x, int st_y, int val, int st_val) {
	queue<pair<int, int>> q;
	q.push({ st.first,st.second });
	vis[st.first][st.second] = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int j = 0; j < 8; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx<1 || ny<1 || nx>n || ny>n) continue;
			if (vis[nx][ny]) continue;
			if (high[nx][ny] > st_val + val) continue;
			if (high[nx][ny] < st_val) continue;
			vis[nx][ny] = 1;
			q.push({ nx,ny });
		}
	}
	int cnt = obj.size();
	for (int i = 0; i < obj.size(); i++) {
		if (vis[obj[i].first][obj[i].second]) cnt--;
	}
	if (cnt == 0) return 1;
	else return 0;
}