#include <stdio.h>
void func(int roof, int sum_x);
int cnt, sum, i, result;
int arr[21];
int main(void) {
	scanf("%d %d", &cnt, &sum);
	for (i = 0; i < cnt; i++) {
		scanf("%d", &arr[i]);
	}
	if (sum == 0) result--;
	func(0, 0);
	printf("%d", result);
	return 0;
}
void func(int roof, int sum_x) {
	if (roof == cnt) {
		if (sum_x == sum) result++;
		return;
	}
	func(roof + 1, sum_x);
	func(roof + 1, sum_x + arr[roof]);
}