#include <iostream>
#include <algorithm>
using namespace std;
int a, b, x, y;
int main(void) {
	scanf("%d%d%d%d", &a, &b, &x, &y);
	int st = abs(a - b);
	if (st > abs(a - x) + abs(b - y)) {
		printf("%d\n", abs(a - x) + abs(b - y));
		return 0;
	}
	if (st > abs(a - y) + abs(b - x)) {
		printf("%d\n", abs(a - y) + abs(b - x));
		return 0;
	}
	printf("%d\n", st);
	return 0;
}