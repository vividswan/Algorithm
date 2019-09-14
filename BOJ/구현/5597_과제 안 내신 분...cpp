#include <stdio.h>


int main(void) {
	int a, b, c, d, e;
	int arr[31] = { 0, };
	for (b = 1; b <= 28; b++) {
		scanf("%d", &c);
		arr[c] = arr[c] + 1;
	}
	for (a = 1; a <= 30; a++) {
		if (arr[a] == 1) continue;
		else {
			d = a;
			break;
		}
	}
	for (a = a + 1; a <= 30; a++) {
		if (arr[a] == 1) continue;
		else {
			e = a;
			break;
		}
	}
	if (d > e) printf("%d\n%d", e, d);
	else printf("%d\n%d", d, e);
	return 0;
}