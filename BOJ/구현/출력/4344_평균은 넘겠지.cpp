#include <iostream>
using namespace std;
int T;
int main(void) {
	scanf("%d,", &T);
	while (T--) {
		int N;
		int arr[1001];
		int total=0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			total += arr[i];
		}
		double average = ((double)total) / ((double) N);
		double plusAverage = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] > average) plusAverage++;
		}
		printf("%.3lf%%\n", (double)100*(plusAverage / (double)N));
	}
	return 0;
}