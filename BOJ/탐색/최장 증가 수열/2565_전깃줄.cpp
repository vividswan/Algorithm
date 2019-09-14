#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
vector<int> v;
int n, res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		pq.push({ b,a });
	}
	v.push_back(-1);
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		if (now > v.back()) {
			v.push_back(now);
			res++;
		}
		else {
			auto it = lower_bound(v.begin(), v.end(), now);
			*it = now;
		}
	}
	printf("%d\n", n - res);
}