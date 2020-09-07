#include <iostream>
#include <vector>
using namespace std;
int map[10][10];
vector<pair<int, int>> zeroPoint;
int zeroPointCnt;
bool endSwc = false;
void dfs(int x, int y, int cnt) {
	if (endSwc) return;
	bool possible[10];
	for (int i = 1; i <= 9; i++) possible[i] = true;
	for (int i = 1; i <= 9; i++) {
		if (y == i) continue;
		possible[map[x][i]] = false;
	}
	for (int i = 1; i <= 9; i++) {
		if (x == i) continue;
		possible[map[i][y]] = false;
	}
	int xSt = 0;
	if (x % 3 == 0) xSt = x - 3;
	else xSt = x - (x % 3);
	int ySt = 0;
	if (y % 3 == 0) ySt = y - 3;
	else ySt = y - (y % 3);
	for (int i = xSt + 1; i <= xSt + 3; i++) {
		for (int j = ySt + 1; j <= ySt + 3; j++) {
			if (x == i && y == j) continue;
			possible[map[i][j]] = false;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (possible[i]) {
			if (cnt == zeroPointCnt) {
				map[x][y] = i;
				for (int i = 1; i <= 9; i++) {
					for (int j = 1; j <= 9; j++) {
						printf("%d", map[i][j]);
					}
					printf("\n");
				}
				endSwc = true;
				return;
			}
			else {
				map[x][y] = i;
				dfs(zeroPoint[cnt].first, zeroPoint[cnt].second, cnt + 1);
				map[x][y] = 0;
			}
		}
	}
}
int main(void) {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%1d", &map[i][j]);
				if (map[i][j] == 0) {
					zeroPoint.push_back({ i,j });
					zeroPointCnt++;
				}
		}
	}
	dfs(zeroPoint[0].first, zeroPoint[0].second, 1);
	return 0;
}