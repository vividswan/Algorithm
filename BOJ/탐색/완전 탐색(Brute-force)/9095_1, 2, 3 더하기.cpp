#include <iostream>
using namespace std;
int res;
void go(int cnt, int n, int sum);
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int i = 0; i < roof; i++) {
		int n;
		scanf("%d", &n);
		res = 0;
		go(0, n, 0);
		printf("%d\n", res);
	}
}
void go(int cnt, int n, int sum) {
	if (cnt > n) return;
	if (sum == n) {
		res++;
		return;
	}
	go(cnt + 1, n, sum + 1);
	go(cnt + 1, n, sum + 2);
	go(cnt + 1, n, sum + 3);
}