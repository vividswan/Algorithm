#include <iostream>
#define MOD (1000000000+7)
using namespace std;
int T,val;
long long function(int val) {
	if (val == 0) return 1;
	long long halfVal = function(val / 2);
	return (halfVal * halfVal * (val % 2 + 1)) % MOD;
}
int main(void) {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &val);
		if (val == 1) {
			printf("%d\n", 1);
			continue;
		}
		printf("%lld\n", function(val-2));
	}
	return 0;
}