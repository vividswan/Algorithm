#include <stdio.h>
int main(void) {
	int a, b, c, d, e, f, arr[51];
	scanf("%d", &a);
	for (b = 1; a >= b; b++) {
		f = 2 * b;
		scanf("%d %d", &c, &d);
		for (e = 0; d >= e; e++) {
			if (c != e + 2 * (d - e)) continue;
			else {
				arr[f - 1] = e;
				arr[f] = (d - e);
			}
		}
	}
	for (b = 1; a >= b; b++) {
		f = 2 * b;
		printf("%d %d\n", arr[f - 1], arr[f]);
	}
	return 0;
}