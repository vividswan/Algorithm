#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1000001;
int n;
int vis[MAX];
queue<int> q;
int main(void) {
	scanf("%d", &n);
	q.push(1);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0) next = now + 1;
			else if (i == 1) next = 2 * now;
			else next = 3 * now;
			if (next > MAX - 1) continue;
			if (vis[next]) continue;
			vis[next] = vis[now] + 1;
			q.push(next);
		}
	}
	printf("%d\n", vis[n]);
	return 0;
}