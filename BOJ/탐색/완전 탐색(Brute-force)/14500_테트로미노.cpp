#include <iostream>
#include <algorithm>
using namespace std;
int n,m,res;
int map[501][501];
void makeSum(int i, int j);
int main(void) {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			makeSum(i, j);
		}
	}
	printf("%d\n", res);
}
void makeSum(int i, int j) {
	int sum = 0;
	if (j + 3 <= m) {
		sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
		res = max(res, sum);
	}
	if (i + 3 <= n) {
		sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
		res = max(res, sum);
	}
	if (i + 1 <= n && j + 1 <= m) {
		sum = map[i][j] + map[i][j + 1] + map[i + 1][j] + map[i + 1][j + 1];
		res = max(res, sum);
	}
	if (i + 2 <= n && j + 1 <= m) {
		sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
		res = max(res, sum);
		sum= map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i+2][j + 1];
		res = max(res, sum);
		sum = map[i][j+1] + map[i + 1][j+1] + map[i + 2][j+1] + map[i][j];
		res = max(res, sum);
		sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i+2][j];
		res = max(res, sum);
		sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
		res = max(res, sum);
		sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j] + map[i + 2][j];
		res = max(res, sum);
		sum = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i+1][j + 1];
		res = max(res, sum);
		sum = map[i][j + 1] + map[i + 1][j + 1] + map[i + 2][j + 1] + map[i+1][j];
		res = max(res, sum);
	}
	if (i + 1 <= n && j + 2 <= m) {
		sum = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		res = max(res, sum);
		sum = map[i][j+2] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2];
		res = max(res, sum);
		sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
		res = max(res, sum);
		sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j+2];
		res = max(res, sum);
		sum = map[i + 1][j] + map[i + 1][j + 1] + map[i][j + 1] + map[i][j + 2];
		res = max(res, sum);
		sum = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
		res = max(res, sum);
		sum = map[i + 1][j] + map[i + 1][j + 1] + map[i + 1][j + 2] + map[i][j + 1];
		res = max(res, sum);
		sum = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
		res = max(res, sum);
	}
	res = max(res, sum);
}