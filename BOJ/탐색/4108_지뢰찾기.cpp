#include <iostream>
using namespace std;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
int main(void) {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0) break;
		getchar();
		char map[101][101];
		for (int i = 0; i < a; i++) {
			cin.getline(map[i], 101);
		}
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				if (map[i][j] == '*') {
					printf("*");
					continue;
				}
				int cnt = 0;
				for (int k = 0; k < 8; k++) {
					int nj = j + dx[k];
					int ni = i + dy[k];
					if (0 <= nj && nj < b && 0 <= ni && ni < a) {
						if (map[ni][nj] == '*') cnt++;
					}
				}
				printf("%d", cnt);
			}
			printf("\n");
		}
	}
	return 0;
}