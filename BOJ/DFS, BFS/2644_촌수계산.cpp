#include <iostream>
#include <queue>
using namespace std;
int f, s, g, u, d;
int vis[1000001];
int dx[3];
queue<int> q;
int main(void) {
	scanf("%d%d%d%d%d", &f, &s, &g, &u, &d);
	dx[0] = u;
	dx[1] = -d;
	vis[s] = 1;
	q.push(s);
	while (!q.empty()) {
		int now = q.front();
		if (now == g) {
			printf("%d\n", vis[now] - 1);
			return 0;
		}
		q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = now + dx[i];
			if (nx<1 || nx>f) continue;
			if (!vis[nx]) {
				vis[nx] += vis[now] + 1;
				q.push(nx);
			}
		}
	}
	printf("use the stairs\n");
}