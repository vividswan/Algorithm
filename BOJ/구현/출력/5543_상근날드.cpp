#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int n = 2001;
	int m = 2001;
	for (int i = 1; i <= 3; i++) {
		int val;
		scanf("%d", &val);
		n = min(n, val);
	}
	for (int i = 1; i <= 2; i++) {
		int val;
		scanf("%d", &val);
		m = min(m, val);
	}
	printf("%d\n", n + m - 50);
	return 0;
}