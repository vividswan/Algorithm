#include<stdio.h>
int main(void) {
	int arr[10];
	for (int a = 0; 8 > a; a++) {
		scanf("%d", &arr[a]);
	}
	int station[5];
	station[0] = -arr[0] + arr[1];
	station[1] = station[0] - arr[2] + arr[3];
	station[2] = station[1] - arr[4] + arr[5];
	station[3] = station[2] - arr[6] + arr[7];
	int max = station[0];
	for (int a = 0; 3 >= a; a++) {
		if (max < station[a]) max = station[a];
	}
	printf("%d", max);
	return 0;
}