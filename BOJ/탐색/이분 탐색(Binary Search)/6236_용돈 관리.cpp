#include <iostream>
#include <algorithm>
using namespace std;
int le = 0;
int ri = 1000000001;
int arr[100001];
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		le = max(le, arr[i]);
	}
	while (le <= ri) {
		int swc = 0;
		int mi = (le + ri) / 2;
		int now = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (now >= arr[i]) {
				now -= arr[i];
			}
			else {
				if (cnt == m) {
					le = mi + 1;
					swc++;
					break;
				}
				else {
					now = mi - arr[i];
					cnt++;
				}
			}
		}
		if (swc == 0) {
			ri = mi - 1;
		}
	}
	printf("%d\n", ri + 1);
}