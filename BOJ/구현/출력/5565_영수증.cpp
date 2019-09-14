#include<stdio.h>
int main(void) {
	int arr[15];
	for (int b = 0; 10 > b; b++) {
		scanf("%d", &arr[b]);
	}
	for (int a = 1; 10 > a; a++) {
		arr[0] -= arr[a];
	}
	printf("%d", arr[0]);
	return 0;
}