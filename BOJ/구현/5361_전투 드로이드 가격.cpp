#include <iostream>
using namespace std;
int main(void) {
	int testCase;
	cin >> testCase;
	while (testCase--) {
		double a, b, c, d, e;
		scanf("%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e);
		double total = 0;
		total += 350.34 * a;
		total += 230.90 * b;
		total += 190.55 * c;
		total += 125.30 * d;
		total += 180.90 * e;
		printf("$%.2lf\n", total);
	}
	return 0;
}