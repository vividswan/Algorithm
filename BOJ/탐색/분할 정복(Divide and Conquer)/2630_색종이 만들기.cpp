#include <iostream>
using namespace std;
int n, map[129][129];
void query(int st_x, int st_y, int ed_x, int ed_y);
int blue, white;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	query(1, 1, n, n);
	printf("%d\n%d", white, blue);
	return 0;
}
void query(int st_x, int st_y, int ed_x, int ed_y) {
	int tot = (ed_x - st_x + 1) * (ed_y - st_y + 1);
	int blue_cnt = 0;
	int white_cnt = 0;
	for (int i = st_y; i <= ed_y; i++) {
		for (int j = st_x; j <= ed_x; j++) {
			if (map[i][j] == 1) blue_cnt++;
			else white_cnt++;
		}
	}
	if (tot == blue_cnt) {
		blue++;
		return;
	}
	else if (tot == white_cnt) {
		white++;
		return;
	}
	else {
		query(st_x, st_y, (st_x + ed_x + 1) / 2 - 1, (st_y + ed_y + 1) / 2 - 1);
		query((ed_x + st_x + 1) / 2, st_y, ed_x, (st_y + ed_y + 1) / 2 - 1);
		query(st_x, (st_y + ed_y + 1) / 2, (st_x + ed_x + 1) / 2 - 1, ed_y);
		query((st_x + ed_x + 1) / 2, (st_y + ed_y + 1) / 2, ed_x, ed_y);
		return;
	}
}