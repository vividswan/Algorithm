#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
int swc;
int arr[100001];
int res_min, res_max;
int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	if (arr[n - 2] - arr[0] == n - 2 && arr[n - 1] - arr[n - 2] > 2) {
		res_min = 2;
		swc++;
	}
	if (arr[n - 1] - arr[1] == n - 2 && arr[1] - arr[0] > 2) {
		res_min = 2;
		swc++;
	}
	int j = 0;
	int a = 0;
	for (int i = 0; i < n; i++) {
		while (j < n - 1 && arr[j + 1] - arr[i] <= n - 1) j++;
		a = max(a, j - i + 1);
	}
	if (swc == 0) res_min = n - a;
	int res_max = max(arr[n - 2] - arr[0], arr[n - 1] - arr[1]) - (n - 2);
	printf("%d\n%d\n", res_min, res_max);
	return 0;
}