#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int n;
int k = 10;
int main(void) {
	scanf("%d", &n);
	while (1) {
		if (n > k) {
			if ((n % k) / (k / 10) >= 5) {
				n = n + ((10 - (n % k) / (k / 10))) * (k / 10);
				k *= 10;
			}
			else {
				n = n - (((n % k) / (k / 10))) * (k / 10);
				k *= 10;
				continue;
			}
		}
		else break;
	}
	printf("%d\n", n);
}