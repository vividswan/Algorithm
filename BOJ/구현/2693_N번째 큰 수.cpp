#include<stdio.h>
int main(void) {
	int num;
	scanf("%d", &num);
	for (int a = 1; num >= a; a++) {
		int arr[11];
		for (int b = 0; 10 > b; b++) {
			scanf("%d", &arr[b]);
		}
		for (int a = 8; a; a--) {
			for (int b = 0; a >= b; b++) {
				if (arr[b] > arr[b + 1]) {
					int temp = arr[b];
					arr[b] = arr[b + 1];
					arr[b + 1] = temp;
				}
			}
		}
		printf("%d\n", arr[7]);
	}
}