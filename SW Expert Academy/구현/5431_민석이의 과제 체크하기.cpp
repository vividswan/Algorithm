#include <iostream>
#include <cstring>
using namespace std;
int T, total;
int main(void) {
	scanf("%d", &T);
	total = T;
	while (T--) {
		int N, K;
		scanf("%d%d", &N, &K);
		int checkIdx[101];
		memset(checkIdx, 0, sizeof(checkIdx));
		for (int i = 1; i <= K; i++) {
			int number;
			scanf("%d", &number);
			checkIdx[number] = 1;
		}
		printf("#%d ", total - T);
		for (int i = 1; i <= N; i++) {
			if (!checkIdx[i]) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}