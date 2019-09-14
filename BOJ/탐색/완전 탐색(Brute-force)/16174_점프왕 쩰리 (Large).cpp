#include <stdio.h>
int arr[70][70];
int arr2[70][70];
void func(int, int);
int num, result;
int main() {
	int i, j;
	scanf("%d ", &num);
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	func(0, 0);
	if (result > 0) {
		printf("HaruHaru");
	}
	else printf("Hing");
	return 0;
}
void func(int a, int b) {
	if (a > num - 1 || b > num - 1) {
		return;
	}
	if (arr2[a][b] == 1) return;
	arr2[a][b]++;
	if (arr[a][b] == -1) {
		result++;
		return;
	}
	else {
		func(a + arr[a][b], b);
		func(a, b + arr[a][b]);
	}
	return;
}