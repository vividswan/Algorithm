#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n,res;
int vis[1001][1001];
queue < pair<int, pair<int, int>>> q;
int main(void) {
	scanf("%d", &n);
	memset(vis, -1, sizeof(vis));
	vis[1][0] = 1;
	q.push({ 1,{0,0} });
	while (!q.empty()) {
		int now = q.front().first;
		int save = q.front().second.first;
		int cnt = q.front().second.second;
		if (now == n) {
			res = cnt;
			break;
		}
		q.pop();
		if (vis[now - 1][save] == -1) {
			if (now - 1 > 0) {
				vis[now - 1][save] = 1;
				q.push({ now - 1,{save,cnt + 1} });
			}
		}
		if (vis[now][now] == -1) {
			vis[now][now] = 1;
			q.push({ now,{now,cnt + 1} });
		}
		if (save != 0) {
			if (now+save<=1000) {
				if (vis[now + save][save] == -1) {
					vis[now + save][save] = 1;
					q.push({ now + save,{save,cnt + 1} });
				}
			}
		}
	}
	printf("%d\n", res);
	return 0;
}