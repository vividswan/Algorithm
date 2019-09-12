#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, pre[10001], go_line[10001], back_line[10001], res[10001], vis[10001];
vector<pair<int, int>> go[10001];
vector<pair<int, int>> back[10001];
queue<int> q;
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, wait;
		cin >> a >> b >> wait;
		go[a].push_back(make_pair(b, wait));
		go_line[b]++;
		back[b].push_back(make_pair(a, wait));
		back_line[a]++;
	}
	int st, fin;
	cin >> st >> fin;
	res[st] = 0;
	q.push(st);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < go[now].size(); i++) {
			int next = go[now][i].first;
			res[next] = max(res[next], res[now] + go[now][i].second);
			go_line[next]--;
			if (go_line[next] == 0) {
				q.push(next);
			}
		}
	}
	int cnt = 0;
	queue<int> cq;
	cq.push(fin);
	while (!cq.empty()) {
		int now = cq.front();
		cq.pop();
		for (int i = 0; i < back[now].size(); i++) {
			int check = back[now][i].first;
			if (res[now] == res[check] + back[now][i].second) {
				cnt++;
				if (check != st && vis[check] == 0) cq.push(check);
				vis[check]++;
			}
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 0; i < back[j].size(); i++) {
			int check = back[j][i].first;
			if (res[j] == res[check] + back[j][i].second) pre[j] = back[j][i].first;
		}
	}
	cout << res[fin] << endl;
	cout << cnt;
}