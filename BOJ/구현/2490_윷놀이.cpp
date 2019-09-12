#include<stdio.h>
int main(void) {
	int arr[13];
	int result1 = 0;
	int result2 = 0;
	int result3 = 0;
	for (int a = 0; 12 > a; a++) {
		scanf("%d", &arr[a]);
	}
	for (int a = 0; 4 > a; a++) {
		result1 += arr[a];
	}
	for (int a = 0; 4 > a; a++) {
		result2 += arr[a + 4];
	}
	for (int a = 0; 4 > a; a++) {
		result3 += arr[a + 8];
	}
	if (result1 == 3) printf("A\n");
	else if (result1 == 2) printf("B\n");
	else if (result1 == 1) printf("C\n");
	else if (result1 == 0) printf("D\n");
	else if (result1 == 4) printf("E\n");
	if (result2 == 3) printf("A\n");
	else if (result2 == 2) printf("B\n");
	else if (result2 == 1) printf("C\n");
	else if (result2 == 0) printf("D\n");
	else if (result2 == 4) printf("E\n");
	if (result3 == 3) printf("A");
	else if (result3 == 2) printf("B");
	else if (result3 == 1) printf("C");
	else if (result3 == 0) printf("D");
	else if (result3 == 4) printf("E");
	return 0;
}