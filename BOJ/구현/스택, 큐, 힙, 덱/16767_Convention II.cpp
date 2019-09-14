#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int n, time, swc, res;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		pq.push({ a,{b,i} });
	}
	while (1) {
		time++;
		if (swc) swc--;
		while (!pq.empty() && pq.top().first == time) {
			q.push({ pq.top().second.second,{pq.top().second.first,pq.top().first} });
			pq.pop();
		}
		if (swc == 0) {
			if (!q.empty()) {
				swc = q.top().second.first;
				res = max(res, time - q.top().second.second);
				q.pop();
			}
		}
		if (pq.empty() && q.empty()) break;
	}
	printf("%d\n", res);
}