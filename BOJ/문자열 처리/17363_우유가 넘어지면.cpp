#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m;
char map[101][101];
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == '-') map[i][j] = '|';
			else if (map[i][j] == '|') map[i][j] = '-';
			else if (map[i][j] == 47) map[i][j] = 92;
			else if (map[i][j] == 92) map[i][j] = 47;
			else if (map[i][j] == '^') map[i][j] = '<';
			else if (map[i][j] == '<') map[i][j] = 'v';
			else if (map[i][j] == 'v') map[i][j] = '>';
			else if (map[i][j] == '>') map[i][j] = '^';
		}
	}
	for (int j = m; j > 0; j--) {
		for (int i = 1; i <= n; i++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}