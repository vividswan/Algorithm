#include <iostream>
using namespace std;
int n;
int swc;
void go(int n);
int main(void) {
	scanf("%d", &n);
	n--;
	while (1) {
		if (swc) break;
		n++;
		go(n);
	}
	printf("%d\n", n);
}
void go(int n) {
	int div_n = 0;
	int now = n;
	while (now) {
		div_n += now % 10;
		now /= 10;
	}
	if (n % div_n == 0) swc = 1;
}