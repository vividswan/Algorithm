#include <iostream>
#include <queue>
using namespace std;
long long n, sum, fir_val, sec_val;
queue<long long> q;
int main(void) {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) {
		long long val;
		scanf("%lld", &val);
		q.push(val);
	}
	scanf("%lld%lld", &fir_val, &sec_val);
	while (!q.empty()) {
		long long now = q.front();
		q.pop();
		sum += 1;
		now -= fir_val;
		if (now <= 0) continue;
		if (!(now % sec_val)) {
			sum += now / sec_val;
			continue;
		}
		else sum += (now / sec_val) + 1;
	}
	printf("%lld\n", sum);
}