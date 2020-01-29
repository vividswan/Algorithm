#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int R, C, T;
int map[51][51];
int st, ed;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d%d%d", &R, &C, &T);
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == -1) {
				if (st == 0) st = i;
				else ed = i;
			}
		}
	}
	while (T--) {
		queue<pair<int, pair<int, int>>> q; // q.push({��,{��,��}});
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (map[i][j] > 0) q.push({ map[i][j],{ i,j } });
			}
		}
		while (!q.empty()) {
			int x = q.front().second.first;
			int y = q.front().second.second;
			int now_val = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (map[nx][ny] == -1) continue;
				if (nx > R || ny > C || nx < 1 || ny < 1) continue;
				map[nx][ny] += now_val / 5;
				map[x][y] -= now_val / 5;
			}
		}
		// �ݽð�, �ð�������� ������ ���� �ܼ� ����
		for (int i = st - 1; i >= 2; i--) map[i][1] = map[i - 1][1];
		for (int i = 1; i < C; i++) map[1][i] = map[1][i + 1];
		for (int i = 1; i < st; i++) map[i][C] = map[i + 1][C];
		for (int i = C; i > 2; i--) map[st][i] = map[st][i - 1];
		map[st][2] = 0;
		for (int i = ed + 1; i < R; i++) map[i][1] = map[i + 1][1];
		for (int i = 1; i < C; i++) map[R][i] = map[R][i + 1];
		for (int i = R; i > ed; i--) map[i][C] = map[i - 1][C];
		for (int i = C; i > 2; i--) map[ed][i] = map[ed][i - 1];
		map[ed][2] = 0;
	}
	int sum = 0;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			sum += map[i][j];
		}
	}
	printf("%d\n", sum + 2);
	// ����û������ ���� -1�̹Ƿ�, �������� 2�� �����ش�.
}