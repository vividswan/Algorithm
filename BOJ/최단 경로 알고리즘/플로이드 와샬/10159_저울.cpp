#include <iostream>
using namespace std;
char map[101][101] = { 0, };
int main(void) {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 'l';
		map[b][a] = 'w';
	}
	for (int v = 1; v <= n; v++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					if (map[i][v] == 'l' && map[v][j] == 'l') map[i][j] = 'l';
					if (map[i][v] == 'w' && map[v][j] == 'w') map[i][j] = 'w';
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (map[i][j] == 0) cnt++;
			}
		}
		cout << cnt << endl;
		cnt = 0;
	}
	return 0;
}