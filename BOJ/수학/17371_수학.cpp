#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
int n;
int now = 1;
double dist(int a, int b);
double minn;
double maxx;
int chk1, chk2;
int res1, res2;
vector<pair<double, double>> adj;
int main(void) {
	scanf("%d", &n);
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		double a, b;
		scanf("%lf %lf", &a, &b);
		adj[i] = { a,b };
	}
	if (n == 1) {
		printf("%.12lf %.12lf\n", adj[1].first, adj[1].second);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int swc = 0;
		for (int j = 1; j <= n; j++) {
			if (j == i) continue;
			if (swc == 0) {
				swc++;
				maxx = dist(i, j);
				chk1 = i;
				chk2 = j;
			}
			else {
				maxx = max(maxx, dist(i, j));
				if (maxx == dist(i, j)) {
					chk1 = i;
					chk2 = j;
				}
			}
		}
		if (i == 1) {
			minn = maxx;
			res1 = chk1;
			res2 = chk2;
		}
		else {
			minn = min(minn, maxx);
			if (minn == maxx) {
				res1 = chk1;
				res2 = chk2;
			}
		}
	}
	printf("%.12lf %.12lf\n", adj[res1].first, adj[res1].second);
}
double dist(int a, int b) {
	double x = pow((adj[a].first - adj[b].first), 2.0);
	double y = pow((adj[a].second - adj[b].second), 2.0);
	double res = pow((x + y), 0.5);
	return res;
}