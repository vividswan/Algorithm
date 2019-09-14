#include <iostream>
using namespace std;
double a, b, c, d;
double cnt[4];
int main(void) {
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	cnt[0] = a / c + b / d;
	cnt[1] = c / d + a / b;
	cnt[2] = d / b + c / a;
	cnt[3] = b / a + d / c;
	double max = 0;
	for (int i = 0; i < 4; i++) {
		if (max < cnt[i]) max = cnt[i];
	}
	for (int i = 0; i < 4; i++) {
		if (max == cnt[i]) {
			printf("%d", i);
			return 0;
		}
	}
}