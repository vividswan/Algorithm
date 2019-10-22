#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int l, u, x;
		scanf("%d%d%d", &l, &u, &x);
		printf("#%d ",i);
		if (x > u) printf("%d\n", -1);
		else if (x > l) printf("%d\n", 0);
		else printf("%d\n", l - x);
	}
	return 0;
}