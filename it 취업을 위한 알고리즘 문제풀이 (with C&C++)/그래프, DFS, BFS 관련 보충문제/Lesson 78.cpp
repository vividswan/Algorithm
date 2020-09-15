#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int v, e;
vector<int> parent;
vector<int> level;
vector<pair<int, pair<int, int>>> edge;
int result;
int find(int idx) {
	if (idx == parent[idx]) return idx;
	return parent[idx] = find(parent[idx]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	if (level[u] > level[v]) swap(u, v);
	parent[u] = v;
	if (level[u] == level[v]) level[v]++;
}
int main(void) {
	cin >> v >> e;
	parent.resize(v + 1);
	level.resize(v + 1);
	for (int i = 1; i <= v; i++) {
		parent[i] = i;
		level[i] = 1;
	}
	for (int i = 1; i <= e; i++) {
		int st, ed, val;
		cin >> st >> ed >> val;
		edge.push_back({ val,{st,ed} });
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < edge.size(); i++) {
		int val = edge[i].first;
		int st = edge[i].second.first;
		int ed = edge[i].second.second;
		if (find(st) == find(ed)) continue;
		merge(st, ed);
		result += val;
	}
	cout << result << '\n';
	return 0;
}