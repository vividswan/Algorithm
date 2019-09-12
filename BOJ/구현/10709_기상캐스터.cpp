#include <iostream>
#include <algorithm>
using namespace std;
char map[101][101];
int res[101][101];
int h, w;
int main(void) {
	scanf("%d%d", &h, &w);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i <= h; i++) {
		int go = 0;
		int swc = -1;
		for (int j = 1; j <= w; j++) {
			if (map[i][j] == 'c') {
				swc = 0;
				if (go == 0) go = 1;
			}
			res[i][j] = swc;
			if (go) swc++;
		}
	}
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
}