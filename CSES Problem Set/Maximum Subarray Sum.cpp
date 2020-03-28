#include <iostream>
#include <algorithm>
using namespace std;
long long arr[200001];
long long nowMaxValue, totalMaxValue;
int N;
int main(void) {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
		totalMaxValue = min(totalMaxValue, arr[i]);
	}
	for (int i = 0; i < N; i++) {
		nowMaxValue = max(arr[i], nowMaxValue+arr[i]);
		totalMaxValue = max(totalMaxValue, nowMaxValue);
	}
	printf("%lld\n", totalMaxValue);
	return 0;
}