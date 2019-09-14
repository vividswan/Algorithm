#include <iostream>
using namespace std;
int main(void) {
	while (1) {
		double a;
		scanf("%lf", &a);
		if (a < 0) break;
		printf("Objects weighing %.2lf on Earth will weigh %.2lf on the moon.\n", a, a * 0.167);
	}
}