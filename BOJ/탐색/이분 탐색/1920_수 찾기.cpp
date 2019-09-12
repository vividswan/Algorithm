#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int arr[100001];
int le, ri;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr + 1, arr + n + 1);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int go;
		scanf("%d", &go);
		le = 1;
		ri = n;
		int swc = 0;
		while (le <= ri) {
			int mid = (le + ri) / 2;
			if (arr[mid] > go) {
				ri = mid - 1;
				continue;
			}
			else if (arr[mid] < go) {
				le = mid + 1;
			}
			else {
				swc = 1;
				break;
			}
		}
		printf("%d\n", swc);
	}
	return 0;
}