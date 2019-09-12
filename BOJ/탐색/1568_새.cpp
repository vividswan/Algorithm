#include <stdio.h>
int main(void) {
	int N, K = 0, result = 0;
	scanf("%d", &N);
	int J = N - K;
	for (K = 1; 1; K++) {
		result++;
		if (K > J) {
			K = 1;
		}
		J -= K;
		if (J == 0) break;
	}
	printf("%d", result);
	return 0;
}