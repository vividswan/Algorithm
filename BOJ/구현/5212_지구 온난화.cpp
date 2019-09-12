#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int r, c;
queue<pair<int, int>>q;
int x_map[11][11];
char map[11][11];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'X') {
				q.push({ i,j });
			}
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		int swc = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || ny<1 || nx>r || ny>c) {
				swc++;
				continue;
			}
			if (map[nx][ny] == '.') swc++;
		}
		if (swc >= 3) x_map[x][y] = 1;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (x_map[i][j]) map[i][j] = '.';
		}
	}
	int max_x = 0;
	int max_y = 0;
	int min_x = 10;
	int min_y = 10;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] == 'X') {
				max_x = max(max_x, i);
				min_x = min(min_x, i);
				max_y = max(max_y, j);
				min_y = min(min_y, j);
			}
		}
	}
	for (int i = min_x; i <= max_x; i++) {
		for (int j = min_y; j <= max_y; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}