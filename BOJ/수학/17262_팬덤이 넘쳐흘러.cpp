#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int mi = 100001;
int ma = 0;
int n;
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		mi = min(b, mi);
		ma = max(a, ma);
	}
	if (ma - mi < 0) printf("0\n");
	else printf("%d", ma - mi);
}