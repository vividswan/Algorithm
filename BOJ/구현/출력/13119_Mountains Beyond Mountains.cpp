#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> mt;
int n, m, x;
int main(void) {
	scanf("%d %d %d", &n, &m, &x);
	mt.resize(m + 1);
	for (int i = 0; i < m; i++) {
		int h;
		scanf("%d", &h);
		int rem = n - h;
		for (int j = 0; j < h; j++) {
			mt[i].push_back('#');
		}
		for (int j = 0; j < rem; j++) {
			mt[i].push_back('.');
		}
	}
	for (int i = 0; i < m; i++) {
		if (mt[i][x - 1] == '#') mt[i][x - 1] = '*';
		else mt[i][x - 1] = '-';
	}
	for (int i = 0; i < m; i++) {
		if ((i + 1) % 3) continue;
		else {
			for (int j = 0; j < n; j++) {
				if (j >= x - 1) break;
				else if (mt[i][j] == '#') continue;
				else mt[i][j] = '|';
			}
		}
	}
	for (int j = n - 1; j >= 0; j--) {
		for (int i = 0; i < m; i++) {
			printf("%c", mt[i][j]);
		}
		printf("\n");
	}
	return 0;
}