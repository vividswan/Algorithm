#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
int n, l, vis[100001], vis_loc[100001], st, ed;
int res = 100010;
vector<int> line[100001];
vector<int> loc[100001];
queue<pair<int, pair<int, int>>> q;
int main(void) {
	scanf("%d %d", &n, &l);
	for (int i = 1; i <= l; i++) {
		while (1) {
			int a;
			scanf("%d", &a);
			if (a == -1) break;
			line[i].push_back(a);
			loc[a].push_back(i);
		}
	}
	scanf("%d %d", &st, &ed);
	for (int i = 1; i <= l; i++) {
		int size = line[i].size();
		for (int j = 0; j < size; j++) {
			if (line[i][j] == st) {
				vis[i] = 1;
				int size = line[i].size();
				for (int k = 0; k < size; k++) {
					q.push({ line[i][k],{i,0} });
				}
			}
		}
	}
	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		if (p.first == ed) {
			printf("%d\n", p.second.second);
			return 0;
		}
		if (vis_loc[p.first] == 0) {
			vis_loc[p.first] = 1;
			int loc_size = loc[p.first].size();
			for (int k = 0; k < loc_size; k++) {
				if (vis[loc[p.first][k]] == 0) {
					vis[loc[p.first][k]] = 1;
					int line_size = line[loc[p.first][k]].size();
					for (int j = 0; j < line_size; j++) {
						q.push({ line[loc[p.first][k]][j],{loc[p.first][k],p.second.second + 1} });
					}
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}