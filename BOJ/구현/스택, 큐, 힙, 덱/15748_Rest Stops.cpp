#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue < pair<long long, long long>, vector<pair<long long, long long>> > pq;
long long l, n, f, b;
long long res;
long long now_del;
long long max_num;
int main(void) {
	scanf("%lld%lld%lld%lld", &l, &n, &f, &b);
	for (int i = 1; i <= n; i++) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		pq.push({ b,a });
	}
	while (!pq.empty()) {
		long long now_lot = pq.top().second;
		long long now_val = pq.top().first;
		pq.pop();
		if (max_num > now_lot) continue;
		long long able = now_lot * (f - b) - now_del;
		max_num = now_lot;
		now_del += able;
		res += able * now_val;
	}
	printf("%lld\n", res);
	return 0;
}