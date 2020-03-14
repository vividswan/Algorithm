#include <iostream>
#include <algorithm>
using namespace std;
int N, sum, val, maxx;
int dist[50001];
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &dist[i]);
		sum += dist[i];
	}
	for (int i = 0; i < N - 1; i++) {
		val = sum;
		for (int j = i + 1; j < N; j++) {
			val -= dist[j];
			maxx = max(maxx, min(val, sum - val));
		}
	}
	printf("%d\n", maxx);
	return 0;
}