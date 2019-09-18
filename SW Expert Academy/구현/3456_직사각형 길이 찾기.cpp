#include <iostream>
using namespace std;
int t;
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int a, b, c,ans;
		scanf("%d%d%d", &a, &b, &c);
		if (a == b && b == c) ans = a;
		else if (a == b && b != c) ans = c;
		else if (a != b && b == c) ans = a;
		else ans = b;
		printf("#%d %d\n", i, ans);
	}
	return 0;
}