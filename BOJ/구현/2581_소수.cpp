#include<stdio.h>
int main(void) {
	int roof1, roof2;
	int first_test = 1;
	int first;
	int sum = 0;
	scanf("%d %d", &roof1, &roof2);
	for (int a = roof1; roof2 >= a; a++) {
		int num = 0;
		for (int b = 1; a >= b; b++) {
			if (a % b == 0) num++;
		}
		if (num == 2) {
			if (first_test == 1) {
				first = a;
				first_test = 0;
			}
			sum += a;
		}
	}
	if (sum == 0) printf("-1");
	else {
		printf("%d\n%d", sum, first);
	}
	return 0;
}