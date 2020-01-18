#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n, m;
long long sum;
priority_queue<long long, vector<long long>, greater<>>pq;
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		long long value;
		scanf("%lld", &value);
		pq.push(value);
		sum += value;
	}
	for (int i = 1; i <= m; i++) {
		long long minn_val1 = pq.top();
		pq.pop();
		sum += minn_val1;
		long long minn_val2 = pq.top();
		pq.pop();
		sum += minn_val2;
		long long temp = minn_val1;
		minn_val1 += minn_val2;
		minn_val2 += temp;
		pq.push(minn_val1);
		pq.push(minn_val2);
	}
	printf("%lld\n", sum);
	return 0;
}