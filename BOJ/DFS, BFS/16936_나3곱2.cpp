#include <iostream>
#include <vector>
using namespace std;
int N;
vector<long long> adj;
vector<long long> res;
vector<pair<long long, long long>> v;
void DFS(long long st) {
	res.push_back(st);
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first == st) DFS(v[i].second);
	}
}
int main(void) {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		long long val;
		scanf("%lld", &val);
		adj.push_back(val);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (2 * adj[i] == adj[j]) v.push_back({ adj[i],adj[j] });
			if (3 * adj[i] == adj[j]) v.push_back({ adj[j],adj[i] });
		}
	}
	for (int i = 0; i < N; i++) {
		res.clear();
		DFS(v[i].first);
		if (res.size() == N) break;
	}
	for (int i = 0; i < N; i++) printf("%lld ", res[i]);
	return 0;
}