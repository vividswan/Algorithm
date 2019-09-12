#include<stdio.h>
int main(void) {
	int arr[10];
	int result = 0;
	for (int a = 0; 5 > a; a++) {
		scanf("%d", &arr[a]);
	}
	for (int a = 0; 5 > a; a++) {
		result += arr[a] * arr[a];
	}
	printf("%d", result % 10);
	return 0;
}