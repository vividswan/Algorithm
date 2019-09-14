#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001];
int res;
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[a]++;
		arr[b]++;
	}
	for (int i = 1; i <= n; i++) {
		res = max(res, arr[i]);
	}
	printf("%d\n", res + 1);
}