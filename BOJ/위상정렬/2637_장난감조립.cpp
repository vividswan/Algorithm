#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> adj[102];
queue<int> q;
int wait[102][102], line[102], res[102][102];
int main(void) {
	int roof, fin;
	cin >> fin >> roof;
	for (int i = 1; i <= roof; i++) {
		int x, y, v;
		cin >> x >> y >> v;
		adj[y].push_back(x);
		wait[x][y] = v;
		line[x]++;
	}
	for (int i = 1; i <= roof; i++) {
		if (line[i] == 0) {
			q.push(i);
			res[i][i] = 1;
		}
	}
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			line[next]--;
			for (int i = 1; i <= fin; i++) {
				if (res[i][i] == 1) {
					res[next][i] += res[now][i] * wait[next][now];
				}
			}
			if (line[next] == 0) q.push(next);
		}
	}
	for (int i = 1; i <= fin; i++) {
		if (res[i][i] == 1) {
			cout << i << ' ' << res[fin][i] << endl;
		}
	}
	return 0;
}