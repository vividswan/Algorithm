#include <iostream>
using namespace std;
long long N;
int main(void) {
	scanf("%lld", &N);
	while (1) {
		printf("%lld ", N);
		if (N == 1) break;
		else if (N % 2) N = 3 * N + 1;
		else N /= 2;
	}
	printf("\n");
	return 0;
}