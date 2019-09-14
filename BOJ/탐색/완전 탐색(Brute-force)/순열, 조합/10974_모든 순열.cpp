#include <iostream>
using namespace std;
int res[9], check[9];
void go(int index, int n);
int main(void) {
	int n;
	scanf("%d", &n);
	go(1, n);
	return 0;
}
void go(int index, int n) {
	if (index > n + 1) return;
	if (index == n + 1) {
		for (int i = 1; i <= n; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			check[i] = 1;
			res[index] = i;
			go(index + 1, n);
			check[i] = 0;
		}
	}
}