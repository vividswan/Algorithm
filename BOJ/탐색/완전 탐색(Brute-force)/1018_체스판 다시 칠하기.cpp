#include <iostream>
#include <algorithm>
using namespace std;
int minResult = 65;
int map[51][51];
int main(void) {
	int N, M;
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char str;
			scanf(" %c", &str);
			if (str == 'W') map[i][j] = 1;
			else map[i][j] = -1;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (N - i < 7 || M - j < 7) continue;
			int result = 0;
			int st;
			for (int k = i; k <= i + 7; k++) {
				for (int l = j; l <= j + 7; l++) {
					if (k == i && l == j) {
						st = map[i][j];
						continue;
					}
					st *= -1;
					if (st != map[k][l]) result++;
				}
				st *= -1;
			}
			minResult = min(minResult, result);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (N - i < 7 || M - j < 7) continue;
			int result = 0;
			int st;
			for (int k = i; k <= i + 7; k++) {
				for (int l = j; l <= j + 7; l++) {
					if (k == i && l == j) {
						st = map[i][j]*(-1);
						result++;
						continue;
					}
					st *= -1;
					if (st != map[k][l]) result++;
				}
				st *= -1;
			}
			minResult = min(minResult, result);
		}
	}
	printf("%d\n", minResult);
	return 0;
}