#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parent;
vector<int> level;
int N, M;
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
	cin >> N >> M;
	parent.resize(N + 1);
	level.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		level[i] = 1;
		parent[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		merge(num1, num2);
	}
	int result1, result2;
	cin >> result1 >> result2;
	if (find(result1) == find(result2)) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}