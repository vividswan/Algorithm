#include <stdio.h>
int main(void) {
	int roof;
	int arr[8];
	scanf("%d", &roof);
	for (int i = 0; i < roof; i++) {
		for (int j = 0; j < 8; j++) scanf("%d", &arr[j]);
		for (int j = 0; j < 4; j++) arr[j] += arr[j + 4];
		if (arr[0] < 1) arr[0] = 1;
		if (arr[1] < 1) arr[1] = 1;
		if (arr[2] < 0) arr[2] = 0;
		printf("%d\n", 1 * arr[0] + 5 * arr[1] + 2 * arr[2] + 2 * arr[3]);
	}
	return 0;
}