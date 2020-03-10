#include <iostream>
#define MOD (1000000009)
using namespace std;
int N;
long long now = 1;
int main(void) {
	scanf("%d", &N);
	long long pre = 1;
	for (int i = 2; i <= N; i++) {
		now = ((2 *i - 1) * pre) % MOD;
		pre = now;
	}
	printf("%lld\n", now);
	return 0;
}