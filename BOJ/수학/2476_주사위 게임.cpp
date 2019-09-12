#include <stdio.h>
int main(void) {
	int a, b, c, max;
	int arr[3001] = { 0, };
	scanf("%d", &a);
	for (b = 1; a >= b; b++) {
		c = 3 * b;
		scanf("%d %d %d", &arr[c - 2], &arr[c - 1], &arr[c]);
	}
	for (b = 1; a >= b; b++) {
		c = 3 * b;
		if (arr[c - 2] == arr[c - 1] && arr[c - 1] == arr[c]) arr[c - 2] = 10000 + arr[c] * 1000;
		else if (arr[c - 2] != arr[c - 1] && arr[c - 1] != arr[c] && arr[c - 2] != arr[c]) {
			if (arr[c] > arr[c - 1] && arr[c] > arr[c - 2]) arr[c - 2] = 100 * arr[c];
			else if (arr[c - 1] > arr[c - 2] && arr[c - 1] > arr[c]) arr[c - 2] = 100 * arr[c - 1];
			else arr[c - 2] = 100 * arr[c - 2];
		}
		else {
			if (arr[c] == arr[c - 1]) arr[c - 2] = 1000 + 100 * arr[c];
			else if (arr[c] == arr[c - 2]) arr[c - 2] = 1000 + 100 * arr[c];
			else arr[c - 2] = 1000 + 100 * arr[c - 1];
		}
	}
	max = arr[1];
	for (b = 1; a >= b; b++) {
		c = 3 * b;
		if (arr[c - 2] >= max) max = arr[c - 2];
	}
	printf("%d", max);
	return 0;
}