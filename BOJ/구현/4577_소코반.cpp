#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int game;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int main(void) {
	while (1) {
		int r;
		int c;
		int not_ed = 0;
		char map[16][16];
		char str[51];
		pair<int, int> st;
		game++;
		scanf("%d%d", &r, &c);
		if (r == 0 && c == 0) break;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '+') not_ed++;
				if (map[i][j] == 'W') {
					not_ed++;
					st = { i,j };
					map[i][j] = '+';
				}
				else if (map[i][j] == 'w') {
					st = { i,j };
					map[i][j] = '.';
				}
			}
		}
		scanf(" %s", str);
		int len = strlen(str);
		int fin_swc = 0;
		int x = st.first;
		int y = st.second;
		for (int i = 0; i < len; i++) {
			int move;
			if (str[i] == 'U') move = 0;
			else if (str[i] == 'D') move = 1;
			else if (str[i] == 'L') move = 2;
			else move = 3;
			int nx = x + dx[move];
			int ny = y + dy[move];
			if (nx<1 || ny<1 || nx>r || ny>c) continue;
			if (map[nx][ny] == '#') continue;
			if (map[nx][ny] == 'b' || map[nx][ny] == 'B') {
				if (nx + dx[move]<1 || ny + dy[move]<1 || nx + dx[move]>r || ny + dy[move]>c) continue;
				if (map[nx + dx[move]][ny + dy[move]] == '#') continue;
				if (map[nx + dx[move]][ny + dy[move]] == 'b') continue;
				if (map[nx + dx[move]][ny + dy[move]] == 'B') continue;
				if (map[nx + dx[move]][ny + dy[move]] == '+') {
					not_ed--;
					map[nx + dx[move]][ny + dy[move]] = 'B';
					if (map[nx][ny] == 'B') {
						not_ed++;
						map[nx][ny] = '+';
					}
					else map[nx][ny] = '.';
					x = nx;
					y = ny;
					continue;
				}
				if (map[nx + dx[move]][ny + dy[move]] == '.') {
					map[nx + dx[move]][ny + dy[move]] = 'b';
					if (map[nx][ny] == 'B') {
						not_ed++;
						map[nx][ny] = '+';
					}
					else map[nx][ny] = '.';
					x = nx;
					y = ny;
					continue;
				}
			}
			if (not_ed == 0) break;
			x = nx;
			y = ny;
		}
		printf("Game %d: ", game);
		if (not_ed) printf("incomplete\n");
		else printf("complete\n");
		if (map[x][y] == '+') map[x][y] = 'W';
		else map[x][y] = 'w';
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}