#include<stdio.h>
int main(void) {
	int x, y, y_cut, y_add, p, min, sum_x, sum_y;
	scanf("%d %d %d %d %d", &x, &y, &y_cut, &y_add, &p);
	sum_x = p * x;
	if (p > y_cut) sum_y = y + y_add * (p - y_cut);
	else if (p <= y_cut) sum_y = y;
	if (sum_x >= sum_y) min = sum_y;
	else if (sum_x <= sum_y) min = sum_x;
	printf("%d\n", min);
	return 0;
}