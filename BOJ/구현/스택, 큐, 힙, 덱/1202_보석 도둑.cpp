#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
multiset<long long> s;
priority_queue<pair<long, long>, vector<pair<long, long>>> pq;
int n, k;
long long sum;
int main(void) {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		long long idx, val;
		scanf("%lld%lld", &idx, &val);
		pq.push({ val,idx });
	}
	for (int i = 1; i <= k; i++) {
		long long val;
		scanf("%lld", &val);
		s.insert(val);
	}
	while (!pq.empty()) {
		long long val = pq.top().first;
		long long weight = pq.top().second;
		pq.pop();
		auto now = s.lower_bound(weight);
		if (now == s.end()) continue;
		s.erase(now);
		sum += val;
	}
	printf("%lld\n", sum);
	return 0;
}
