#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int r, c;
int arr[6];
char map[51][51];
int main(void) {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &map[i][j]);
		}
	}
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			int a = 0;
			int b = 0;
			if (map[i][j] == '#') continue;
			else if (map[i][j] == '.') a++;
			else b++;
			if (map[i][j + 1] == '#') continue;
			else if (map[i][j + 1] == '.') a++;
			else b++;
			if (map[i + 1][j] == '#') continue;
			else if (map[i + 1][j] == '.') a++;
			else b++;
			if (map[i + 1][j + 1] == '#') continue;
			else if (map[i + 1][j + 1] == '.') a++;
			else b++;
			if (a == 4) arr[0]++;
			else if (a == 3) arr[1]++;
			else if (a == 2) arr[2]++;
			else if (a == 1) arr[3]++;
			else arr[4]++;
		}
	}
	printf("%d\n%d\n%d\n%d\n%d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
}