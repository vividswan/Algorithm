#include <iostream>
using namespace std;
long long n;
long long go = 1;
long long nn = 2;
int main(void) {
	scanf("%lld", &n);
	while (1) {
		nn *= 2;
		long long res = nn * (go + 1) - 1;
		if (n <= res) break;
		go++;
	}
	printf("%lld\n", go);
	return 0;
}