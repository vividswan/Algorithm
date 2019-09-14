#include <iostream>
#include <algorithm>
using namespace std;
int n;
int arr[101];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int k = n - 1;
	int cnt = 1;
	while (k) {
		if (arr[k] > arr[k + 1]) break;
		else {
			cnt++;
			k--;
		}
	}
	printf("%d\n", n - cnt);
}