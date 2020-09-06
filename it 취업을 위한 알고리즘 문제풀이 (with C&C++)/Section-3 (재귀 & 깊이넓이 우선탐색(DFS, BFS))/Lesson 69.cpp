#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int>>node;
void bfs(int idx) {
	queue<int> q;
	q.push(idx);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';
		for (int i = 0; i < node[now].size(); i++) {
			q.push(node[now][i]);
		}
	}
}
int main(void) {
	node.resize(8);
	for (int i = 0; i < 6; i++) {
		int st, ed;
		cin >> st >> ed;
		node[st].push_back(ed);
	}
	bfs(1);
}