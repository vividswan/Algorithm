#include <iostream>
using namespace std;
bool vis[16][16];
int N;
int result;
void dfs(int x) {
	for (int i = 1; i <= N; i++) {
		bool swc = false;
		int nowX = x;
		int nowY = i;
		while (true) {
			nowX--;
			nowY--;
			if (nowX == 0 || nowY == 0) break;
			if (vis[nowX][nowY]) {
				swc = true;
				break;
			}
		}
		if (swc) continue;
		nowX = x;
		nowY = i;
		while (true) {
			nowX--;
			nowY++;
			if (nowX == 0 || nowY == N+1) break;
			if (vis[nowX][nowY]) {
				swc = true;
				break;
			}
		}
		if (swc) continue;
		nowX = x;
		while (true) {
			nowX--;
			if (nowX == 0) break;
			if (vis[nowX][i]) {
				swc = true;
				break;
			}
		}
		if (swc) continue;
		if (x == N) {
			result++;
			continue;
		}
		vis[x][i] = true;
		dfs(x + 1);
		vis[x][i] = false;
	}
}
int main(void) {
	cin >> N;
	dfs(1);
	cout << result << '\n';
	return 0;
}