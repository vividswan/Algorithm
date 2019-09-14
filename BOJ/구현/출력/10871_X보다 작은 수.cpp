#include <iostream>
using namespace std;
int n, x;
int main(void) {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a < x)printf("%d ", a);
	}
	return 0;
}