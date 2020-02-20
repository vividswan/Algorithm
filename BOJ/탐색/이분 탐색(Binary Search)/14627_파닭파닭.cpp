#include <iostream>
#include <algorithm>
using namespace std;
long long S, C,leftValue,rightValue, midValue,total,res;
long long arr[1000001];
int main(void) {
	scanf("%lld%lld", &S, &C);
	for (int i = 0; i < S; i++) {
		scanf("%lld", &arr[i]);
		total += arr[i];
	}
	leftValue = 1;
	rightValue = 1000000000;
	while (leftValue <= rightValue) {
		midValue = (leftValue + rightValue) / 2;
		long long sum = 0;
		for (int i = 0; i < S; i++) {
			sum += arr[i] / midValue;
		}
		if (sum >= C) {
			res = midValue;
			leftValue = midValue + 1;
		}
		else rightValue = midValue - 1;
	}
	printf("%lld\n", total-C*res);
	return 0;
}