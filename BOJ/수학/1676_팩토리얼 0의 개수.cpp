#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int main(void) {
	int n;
	scanf("%d", &n);
	long long two = 0;
	long long five = 0;
	for (int i = 1; i <= n; i++) {
		int k = i;
		if ((k % 2) == 0) {
			while ((k % 2) == 0) {
				two++;
				k /= 2;
			}
		}
		k = i;
		if ((k % 5) == 0) {
			while ((k % 5) == 0) {
				five++;
				k /= 5;
			}
		}
	}
	printf("%lld\n", min(two, five));
	return 0;
}