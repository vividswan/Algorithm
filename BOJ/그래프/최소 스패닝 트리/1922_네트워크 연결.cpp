#include <iostream>
#include <queue>
using namespace std;
int n, m, par[1001], cnt, sum;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
int find(int idx);
void merge(int a, int b);
int main() {
	fill(par, par + 1001, -1);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pq.push({ c,{a,b} });
	}
	while (cnt != n - 1) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (find(x) != find(y)) {
			merge(x, y);
			sum += cost;
			cnt++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
int find(int idx) {
	if (par[idx] < 0) return idx;
	par[idx] = find(par[idx]);
	return par[idx];
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
}