#include <stdio.h>
int main(void) {
	int arr[9][9];
	int i, j;
	for (i = 0; 9 > i; i++) {
		for (j = 0; 9 > j; j++) scanf("%d", &arr[i][j]);
	}
	int max = 0;
	int i2, j2;
	for (i = 0; 9 > i; i++) {
		for (j = 0; 9 > j; j++) if (arr[i][j] > max) {
			max = arr[i][j];
			i2 = i;
			j2 = j;
		}
	}
	printf("%d\n%d %d", max, i2 + 1, j2 + 1);
}