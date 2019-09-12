#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> pq;
int n;
void merge(int a, int b);
int find(int idx), par[101];
vector<pair<double, double>> star;
double dist(int a, int b);
int main(void) {
	fill(par, par + 101, -1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		star.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			double val = dist(i, j);
			pq.push({ val,{i,j} });
		}
	}
	int cnt = 0;
	double sum = 0;
	while (cnt != n - 1) {
		double cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (find(x) != find(y)) {
			merge(x, y);
			cnt++;
			sum += cost;
		}
	}
	printf("%.2lf\n", sum);
	return 0;
}
double dist(int a, int b) {
	double x = pow((star[a].first - star[b].first), 2.0);
	double y = pow((star[a].second - star[b].second), 2.0);
	double res = pow((x + y), 0.5);
	return res;
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	par[a] = b;
}
int find(int idx) {
	if (par[idx] < 0) return idx;
	par[idx] = find(par[idx]);
	return par[idx];
}