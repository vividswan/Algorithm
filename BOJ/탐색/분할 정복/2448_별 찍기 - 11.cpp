#include <iostream>
#include <queue>
using namespace std;
int map[3073][6144], vis[3073][6144], n;
void go(int y, int x);
void div(int high, int len, int y, int x);
queue <pair<int, int>> q;
int main(void) {
	scanf("%d", &n);
	div(n, (n * 2 - 1), 1, (n * 2 - 1) / 2 + 1);
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		go(p.first, p.second);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n * 2 - 1; j++) {
			if (map[i][j] == 1) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
void go(int y, int x) {
	if (y > n) return;
	map[y][x] = 1;
	map[y + 1][x - 1] = 1;
	map[y + 1][x + 1] = 1;
	map[y + 2][x - 2] = 1;
	map[y + 2][x - 1] = 1;
	map[y + 2][x] = 1;
	map[y + 2][x + 1] = 1;
	map[y + 2][x + 2] = 1;
	return;
}
void div(int high, int len, int y, int x) {
	if (high == 3) {
		if (vis[y][x] == 0) {
			vis[y][x] = 1;
			q.push({ y,x });
			return;
		}
		else return;
	}
	else {
		div(high / 2, high / 2 * 2 - 1, y, x);
		div(high / 2, high / 2 * 2 - 1, y + high / 2, x - (len / 4 + 1));
		div(high / 2, high / 2 * 2 - 1, y + high / 2, x + (len / 4 + 1));
		return;
	}
}