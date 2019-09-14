#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n;
int vis[300][300];
void dfs(int x, int y, int cnt, double po);
double pos[4];
double res;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < 4; i++) {
		double a;
		scanf("%lf", &a);
		pos[i] = a / 100.0;
	}
	vis[150][150] = 1;
	dfs(150, 150, 1, 1);
	printf("%.9lf\n", res);
}
void dfs(int x, int y, int cnt, double po) {
	if (cnt == n + 1) {
		res += po;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (vis[nx][ny]) continue;
		vis[nx][ny] = 1;
		dfs(nx, ny, cnt + 1, po * pos[i]);
		vis[nx][ny] = 0;
	}
}