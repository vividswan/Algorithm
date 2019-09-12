#include <iostream>
using namespace std;
int main(void) {
	int n;
	scanf("%d", &n);
	long long res = 5;
	long long pl = 7;
	for (int i = 2; i <= n; i++) {
		res += pl;
		res = res % 45678;
		pl += 3;
	}
	printf("%lld\n", res);
}