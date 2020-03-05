#include <iostream>
using namespace std;
long long G, realValue=1, memoryValue=1, swc;
int main(void) {
	scanf("%lld", &G);
	while (1) {
		if (realValue * realValue - (realValue - 1) * (realValue - 1) > G) break;
		if (realValue * realValue - memoryValue * memoryValue == G) {
			swc++;
			printf("%lld\n", realValue);
		}
		if (realValue * realValue - memoryValue * memoryValue <= G) {
			realValue++;
			continue;
		}
		else memoryValue++;
	}
	if (!swc) printf("-1\n");
	return 0;
}