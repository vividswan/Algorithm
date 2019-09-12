#include <iostream>
#include <cstring>
using namespace std;
int len;
char str[51];
int dx[] = { 0,-1,0,1 };
int dy[] = { -1,0,1,0 };
int map[201][201];
char res[201][201];
int min_x = 100, min_y = 100, max_x = 100, max_y = 100;
int main(void) {
	scanf("%d", &len);
	scanf(" %s", str);
	int x = 100;
	int y = 100;
	map[100][100] = 1;
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'F') {
			x = x + dx[cnt];
			y = y + dy[cnt];
			if (min_x > x) min_x = x;
			if (min_y > y) min_y = y;
			if (max_x < x) max_x = x;
			if (max_y < y) max_y = y;
			map[y][x] = 1;
		}
		if (str[i] == 'R') {
			if (cnt == 3) cnt = 0;
			else cnt++;
		}
		if (str[i] == 'L') {
			if (cnt == 0) cnt = 3;
			else cnt--;
		}
	}
	for (int i = max_y; i >= min_y; i--) {
		for (int j = min_x; j <= max_x; j++) {
			if (map[i][j] == 1) res[i][j] = '.';
			else res[i][j] = '#';
		}
	}
	for (int i = max_y; i >= min_y; i--) {
		for (int j = min_x; j <= max_x; j++) {
			printf("%c", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}