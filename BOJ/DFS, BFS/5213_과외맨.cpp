#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int vis[255000] = { 0, }, pre[255000];
int n, map[505][1010], ref_map[505][1010];
queue<int> q;
vector<vector<pair<int, int>>> go;
int main(void) {
	scanf("%d", &n);
	int h = 0;
	for (int i = 1; i <= n; i++) {
		if (i % 2) h += n;
		else h += n - 1;
	}
	go.resize(h + 1);
	int index = 1;
	int swc = 1;
	int line = 1;
	for (int i = 1; i <= h; i++) {
		if (swc && index == 2 * n + 1) {
			index = 2;
			line++;
			swc = 0;
		}
		else if (!swc && index == 2 * n) {
			index = 1;
			line++;
			swc = 1;
		}
		int a, b;
		scanf("%d %d", &a, &b);
		map[line][index] = a;
		go[i].push_back({ line,index });
		ref_map[line][index] = i;
		index++;
		map[line][index] = b;
		ref_map[line][index] = i;
		index++;
	}
	q.push(1);
	vis[1] = 1;
	int max_path = 1;
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int y = go[now][0].first;
		int x = go[now][0].second;
		for (int i = 0; i < 4; i++) {
			if (i == 3) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n * 2 && 1 <= ny && ny <= n) {
				int next = ref_map[ny][nx];
				if (vis[next] == 0) {
					if (map[y][x] == map[ny][nx]) {
						vis[next] = vis[now] + 1;
						q.push(next);
						max_path = max(max_path, next);
						pre[next] = now;
					}
				}
			}
		}
		x += 1;
		for (int i = 0; i < 4; i++) {
			if (i == 2) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (1 <= nx && nx <= n * 2 && 1 <= ny && ny <= n) {
				int next = ref_map[ny][nx];
				if (vis[next] == 0) {
					if (map[y][x] == map[ny][nx]) {
						vis[next] = vis[now] + 1;
						q.push(next);
						max_path = max(max_path, next);
						pre[next] = now;
					}
				}
			}
		}
	}
	int res;
	if (vis[h] == 0) res = max_path;
	else res = h;
	printf("%d\n", vis[res]);
	stack<int> s;
	int now = res;
	while (1) {
		s.push(now);
		if (now == 1) break;
		now = pre[now];
	}
	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}