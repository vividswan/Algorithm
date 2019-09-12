#include <iostream>
#include <queue>
using namespace std;
int arr[10001], n, vis[10001];
queue<int> q;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	int st, ed;
	scanf("%d%d", &st, &ed);
	vis[st] = 1;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; arr[now] * i + now <= n; i++) {
			int next = arr[now] * i + now;
			if (vis[next]) continue;
			else {
				vis[next] = vis[now] + 1;
				q.push(next);
			}
		}
		for (int i = 1; arr[now] * (-i) + now > 0; i++) {
			int next = arr[now] * (-i) + now;
			if (vis[next]) continue;
			else {
				vis[next] = vis[now] + 1;
				q.push(next);
			}
		}
	}
	if (vis[ed]) printf("%d\n", vis[ed] - 1);
	else printf("-1\n");
}