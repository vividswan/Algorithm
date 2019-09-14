#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, k, m, vis[100001], vis_line[1001];
vector<vector<int>> line;
vector<vector<int>> num;
queue<int> ser_one;
queue<int> q;
int main(void) {
	scanf("%d%d%d", &n, &k, &m);
	line.resize(m + 1);
	num.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= k; j++) {
			int a;
			scanf("%d", &a);
			line[i].push_back(a);
			if (a == 1) ser_one.push(i);
			num[a].push_back(i);
		}
	}
	while (!ser_one.empty()) {
		int now = ser_one.front();
		ser_one.pop();
		vis_line[now] = 1;
		for (int i = 0; i < line[now].size(); i++) {
			int next = line[now][i];
			if (vis[next]) continue;
			if (next == 1) vis[next] = 1;
			else vis[next] = 2;
			q.push(next);
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < num[now].size(); i++) {
			int next = num[now][i];
			if (vis_line[next]) continue;
			vis_line[next] = 1;
			for (int j = 0; j < line[next].size(); j++) {
				int next_num = line[next][j];
				if (vis[next_num]) continue;
				vis[next_num] = vis[now] + 1;
				q.push(next_num);
			}
		}
	}
	if (vis[n]) printf("%d\n", vis[n]);
	else printf("-1\n");
}