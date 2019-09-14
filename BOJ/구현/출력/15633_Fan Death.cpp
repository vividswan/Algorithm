#include <stdio.h>
int main() {
	int num, i, sum = 0;
	scanf("%d", &num);
	for (i = 1; i <= num; i++) {
		if (num % i == 0) sum += i;
	}
	int result = sum * 5 - 24;
	printf("%d", result);
}