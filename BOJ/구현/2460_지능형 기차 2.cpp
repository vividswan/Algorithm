#include<stdio.h>
int main(void) {
	int arr[50];
	for (int a = 0; 20 > a; a++) {
		scanf("%d", &arr[a]);
	}
	int station[15];
	station[0] = -arr[0] + arr[1];
	station[1] = station[0] - arr[2] + arr[3];
	station[2] = station[1] - arr[4] + arr[5];
	station[3] = station[2] - arr[6] + arr[7];
	station[4] = station[3] - arr[8] + arr[9];
	station[5] = station[4] - arr[10] + arr[11];
	station[6] = station[5] - arr[12] + arr[13];
	station[7] = station[6] - arr[14] + arr[15];
	station[8] = station[7] - arr[16] + arr[17];
	station[9] = station[8] - arr[18] + arr[19];
	int max = station[0];
	for (int a = 0; 9 >= a; a++) {
		if (max < station[a]) max = station[a];
	}
	printf("%d", max);
	return 0;
}