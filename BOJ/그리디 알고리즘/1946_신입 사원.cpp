#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int t;
int main(void) {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int n;
		scanf("%d", &n);
		vector<pair<int, int>> v;
		int res_min = n + 1;
		int res = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
		for (int j = 0; j < n; j++) {
			int a, b;
			scanf("%d%d", &a, &b);
			pq.push({ a,b });
		}
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			if (p.second < res_min) res++;
			res_min = min(res_min, p.second);
		}
		printf("%d\n", res);
	}
}