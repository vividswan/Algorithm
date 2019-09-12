#include <stdio.h>
int main(void) {
	double a, b;
	double c;
	scanf("%lf %lf", &a, &b);
	c = a / b;
	printf("%.10lf", c);
	return 0;
}