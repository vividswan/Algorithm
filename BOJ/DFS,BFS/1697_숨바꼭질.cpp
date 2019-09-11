#include <iostream>
#include <queue>
using namespace std;
int vis[100002], n, k;
queue<pair<int, int>> q;
int main(void) {
	scanf("%d%d", &n, &k);
	vis[n] = 1;
	q.push({ n,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == k) {
			printf("%d", cnt);
			return 0;
		}
		for (int i = 1; i <= 3; i++) {
			int nx;
			if (i == 1) nx = x + 1;
			else if (i == 2) nx = x - 1;
			else nx = x * 2;
			if (nx < 0 || nx>100000) continue;
			if (vis[nx] == 0) {
				vis[nx] = 1;
				q.push({ nx,cnt + 1 });
			}
		}
	}
}