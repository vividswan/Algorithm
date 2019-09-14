#include <iostream>
using namespace std;
int sum[1001], swc;
void ox(int n);
int go(int n) {
	if (n == 1) {
		return sum[n] = 1;
	}
	return sum[n] = n + go(n - 1);
}
int main(void) {
	go(1000);
	int roof;
	scanf("%d", &roof);
	for (int i = 0; i < roof; i++) {
		int n;
		swc = 0;
		scanf("%d", &n);
		ox(n);
		if (swc) printf("1\n");
		else printf("0\n");
	}
}
void ox(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (n == sum[i] + sum[j] + sum[k]) {
					swc++;
					return;
				}
			}
		}
	}
}