#include<stdio.h>
int main(void) {
	int task, sum;
	int arr[51] = { 0 };
	int result = 0;
	int arrsum[51] = { 0 };
	scanf("%d %d", &task, &sum);
	for (int roof = 1; task >= roof; roof++) scanf("%d", &arr[roof]);
	for (int roof = 1; task >= roof; roof++) arrsum[roof] = arrsum[roof - 1] + arr[roof];
	for (int roof = 1; task >= roof; roof++) if (arrsum[roof] > sum) {
		result = roof - 1;
		break;
	}
	else if (roof == task) result = task;
	printf("%d\n", result);
	return 0;
}