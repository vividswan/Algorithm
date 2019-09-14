#include <stdio.h>
int main(void) {
	int a, b, c, d;
	scanf("%d %d %d", &a, &b, &c);
	int arr[3] = { a,b,c };
	for (a = 0; 1 >= a; a++) {
		if (arr[a] > arr[a + 1]) {
			d = arr[a];
			arr[a] = arr[a + 1];
			arr[a + 1] = d;
		}
	}
	if (arr[0] > arr[1]) {
		d = arr[0];
		arr[0] = arr[1];
		arr[1] = d;
	}
	printf("%d", arr[1]);
}