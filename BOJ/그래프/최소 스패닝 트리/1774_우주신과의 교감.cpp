#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<pair<double, pair<int, int >>>e;
int n, m;
void merge(int a, int b);
int find(int idx), par[1001];
vector<pair<double, double>> path;
double dist(int a, int b);
int main(void) {
	fill(par, par + 1001, -1);
	path.push_back({ 0,0 });
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		path.push_back({ a,b });
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (i == j) continue;
			if (find(i) == find(j)) continue;
			double val = dist(i, j);
			e.push_back({ val,{i,j} });
		}
	}
	sort(e.begin(), e.end());
	double sum = 0;
	for (int i = 0; i < e.size(); i++) {
		double cost = e[i].first;
		int x = e[i].second.first;
		int y = e[i].second.second;
		if (find(x) != find(y)) {
			merge(x, y);
			sum += cost;
		}
	}
	printf("%.2lf\n", sum);
	return 0;
}
double dist(int a, int b) {
	double x = pow((path[a].first - path[b].first), 2.0);
	double y = pow((path[a].second - path[b].second), 2.0);
	double res = sqrt(x + y);
	return res;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[b] = a;
}
int find(int idx) {
	if (par[idx] < 0) return idx;
	return par[idx] = find(par[idx]);
}