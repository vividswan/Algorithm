#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
long long val[100001];
long long next_dist[100001];
long long res;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n - 1; i++) {
		scanf("%lld", &next_dist[i]);
	}
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			scanf("%lld", &val[i]);
			continue;
		}
		long long a;
		scanf("%lld", &a);
		val[i] = min(a, val[i - 1]);
	}
	for (int i = 1; i <= n - 1; i++) {
		res += val[i] * next_dist[i];
	}
	printf("%lld\n", res);
	return 0;
}