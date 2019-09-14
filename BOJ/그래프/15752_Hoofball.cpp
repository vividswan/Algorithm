#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, arr[101], vis[101], go[101], res;
queue<int> q;
vector<int> adj;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		adj.push_back(a);
	}
	adj.push_back(9999);
	adj.push_back(-1);
	sort(adj.begin(), adj.end());
	adj[0] = 9999;
	for (int i = 1; i <= n; i++) {
		if (abs(adj[i] - adj[i + 1]) < abs(adj[i] - adj[i - 1])) {
			arr[i + 1] += 1;
			go[i] = i + 1;
		}
		else {
			arr[i - 1] += 1;
			go[i] = i - 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			q.push(i);
			vis[i] = 1;
			res++;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		if (vis[go[now]]) continue;
		else {
			vis[go[now]] = 1;
			q.push(go[now]);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		else {
			res++;
			vis[i] = 1;
			vis[go[i]] = 1;
		}
	}
	printf("%d\n", res);
	return 0;
}