#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[101], last = 1;
int ex[101], not_ex[101];
int maxx, minn;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	ex[1] = 1;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != -1) {
			if (arr[i] > i - last || not_ex[i - arr[i]]) {
				printf("%d\n", -1);
				return 0;
			}
			else {
				last = i - arr[i];
				ex[last] = 1;
				for (int j = last + 1; j <= i; j++) {
					not_ex[j] = 1;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ex[i]) minn++;
		if (!not_ex[i])maxx++;
	}
	printf("%d %d\n", minn, maxx);
	return 0;
}