#include <iostream>
#include <cmath>
using namespace std;
long long n;
long long cnt = 1;
int main(void) {
	scanf("%lld", &n);
	while (cnt + (cnt + 1) * (pow(2, (cnt + 1)) - 1) < n) {
		cnt++;
	}
	printf("%lld\n", cnt);
}