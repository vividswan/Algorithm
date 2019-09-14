#include <iostream>
using namespace std;
int n;
int st = 0;
int res = 0;
int swc = 0;
int main(void) {
	scanf("%d", &n);
	while (st + 8 < n) {
		st += 8;
	}
	for (int i = 1; i <= n - st; i++) {
		if (res == 5) swc = 1;
		if (res == 1) swc = 0;
		if (swc == 0) res++;
		else if (swc == 1) res--;
	}
	printf("%d\n", res);
	return 0;
}