#include <iostream>
#include <algorithm>
using namespace std;
long long m, n, l, arr[100001], res;
int main(void) {
	scanf("%lld %lld %lld", &m, &n, &l);
	for (int i = 0; i < m; i++) {
		long long x;
		scanf("%lld", &x);
		arr[i] = x;
	}
	sort(arr, arr + m);
	for (int i = 0; i < n; i++) {
		long long x, y;
		scanf("%lld %lld", &x, &y);
		if (y > l) continue;
		long long min_x = x - (l - y);
		long long max_x = x + (l - y);
		long long left = 0;
		long long right = m - 1;
		while (left <= right) {
			long long mid = (right + left) / 2;
			if (min_x <= arr[mid] && arr[mid] <= max_x) {
				res++;
				break;
			}
			else if (arr[mid] < min_x) left = mid + 1;
			else right = mid - 1;
		}
	}
	printf("%lld", res);
}