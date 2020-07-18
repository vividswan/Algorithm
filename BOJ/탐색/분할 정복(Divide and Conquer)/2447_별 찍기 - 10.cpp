#include <iostream>
using namespace std;
char map[2188][2188];
void recursion(int N, int x, int y);
int N;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			map[i][j] = ' ';
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			recursion(N, i, j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
	return 0;
}
void recursion(int N, int x, int y) {
	if ((x / N) % 3 == 1 && (y / N) % 3 == 1) return;
	else if (N/3==0) map[x][y] = '*';
	else recursion(N / 3, x, y);
}