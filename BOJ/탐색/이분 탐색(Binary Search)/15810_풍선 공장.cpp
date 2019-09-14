#include <iostream>
using namespace std;
int cnt;
long long n, m, l;
long long arr[1000001];
int main(void) {
	scanf("%lld %lld", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &arr[i]);
	}
	long long now;
	long long max_now = 500000000000;
	long long min_now = 0;
	while (1) {
		long long cnt = 0;
		now = (max_now + min_now) / 2;
		if (now == min_now) break;
		for (int i = 0; i < n; i++)
			cnt += now / arr[i];
		if (cnt >= m)
			max_now = now;
		else
			min_now = now;
	}
	printf("%lld\n", now + 1);
}