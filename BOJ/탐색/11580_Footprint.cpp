#include <iostream>
using namespace std;
int vis[2001][2001] = { 0, };
int cnt, roof;
char mve[1001];
int main(void) {
	cin >> roof >> mve;
	vis[1000][1000] = 1;
	cnt++;
	int x = 1000;
	int y = 1000;
	for (int i = 0; i < roof; i++) {
		if (mve[i] == 'N') y++;
		else if (mve[i] == 'S') y--;
		else if (mve[i] == 'E') x++;
		else if (mve[i] == 'W') x--;
		if (vis[x][y] != 0) continue;
		else {
			cnt++;
			vis[x][y] = 1;
		}
	}
	printf("%d", cnt);
}