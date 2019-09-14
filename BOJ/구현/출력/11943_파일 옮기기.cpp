#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int a, b, c, d, e, f;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	e = a + d;
	f = b + c;
	int res = min(e, f);
	printf("%d\n", res);
}