#include <stdio.h>
double result = 1;
double func(double, double);
int main(void) {
	while (1) {
		double n, k;
		scanf("%lf %lf", &n, &k);
		if (n == 0 && k == 0) return 0;
		else {
			double min = (n - k > k) ? k : n - k;
			if (min == 0) printf("1\n");
			else {
				func(n, min);
				printf("%.0lf\n", result);
				result = 1;
			}
		}
	}
}
double func(double a, double b) {
	result *= (a / b);
	if (b == 1) return result;
	func(a - 1, b - 1);
}