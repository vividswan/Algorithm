#include <iostream>
using namespace std;
int n, map[2188][2188];
void go(int st_x, int st_y, int ed_x, int ed_y);
int min_res, zero_res, pl_res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	go(1, 1, n, n);
	printf("%d\n%d\n%d\n", min_res, zero_res, pl_res);
	return 0;
}
void go(int st_x, int st_y, int ed_x, int ed_y) {
	int min_cnt = 0;
	int zero_cnt = 0;
	int pl_cnt = 0;
	int tot = (ed_x - st_x + 1) * (ed_y - st_y + 1);
	for (int i = st_y; i <= ed_y; i++) {
		for (int j = st_x; j <= ed_x; j++) {
			if (map[i][j] == -1) {
				min_cnt++;
			}
			else if (map[i][j] == 0) {
				zero_cnt++;
			}
			else pl_cnt++;
		}
	}
	if (tot == min_cnt) {
		min_res++;
		return;
	}
	else if (tot == zero_cnt) {
		zero_res++;
		return;
	}
	else if (tot == pl_cnt) {
		pl_res++;
		return;
	}
	else {
		int swc = (ed_x - st_x + 1) / 3;
		go(st_x, st_y, st_x + swc - 1, st_y + swc - 1);
		go(st_x + swc, st_y, st_x + swc * 2 - 1, st_y + swc - 1);
		go(st_x + swc * 2, st_y, st_x + swc * 3 - 1, st_y + swc - 1);
		go(st_x, st_y + swc, st_x + swc - 1, st_y + swc * 2 - 1);
		go(st_x + swc, st_y + swc, st_x + swc * 2 - 1, st_y + swc * 2 - 1);
		go(st_x + swc * 2, st_y + swc, st_x + swc * 3 - 1, st_y + swc * 2 - 1);
		go(st_x, st_y + swc * 2, st_x + swc - 1, st_y + swc * 3 - 1);
		go(st_x + swc, st_y + swc * 2, st_x + swc * 2 - 1, st_y + swc * 3 - 1);
		go(st_x + swc * 2, st_y + swc * 2, st_x + swc * 3 - 1, st_y + swc * 3 - 1);
		return;
	}
}