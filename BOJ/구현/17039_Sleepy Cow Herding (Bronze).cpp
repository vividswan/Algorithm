#include <iostream>
#include <algorithm>
using namespace std;
int a, b, c;
int min_res = 0;
int max_res = 0;
int main(void) {
	scanf("%d %d %d", &a, &b, &c);
	int d, e, f;
	if (a + 1 == b && b + 1 == c) printf("%d\n", 0);
	else if (c - b == 2) printf("%d\n", 1);
	else if (b - a == 2) printf("%d\n", 1);
	else printf("%d\n", 2);
	d = a;
	e = b;
	f = c;
	printf("%d\n", max(b - a, c - b) - 1);
}