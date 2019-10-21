#include <iostream>
#include <algorithm>
using namespace std;
int t;
int main(void) {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n;
		scanf("%d", &n);
		int up = 0;
		int down = 0;
		int arr[1001];
		for (int j = 1; j <= n; j++) scanf("%d", &arr[j]);
		for (int j = 2; j <= n; j++) {
			int val = arr[j] - arr[j - 1];
			if (val > 0) up = max(up, val);
			else down = max(down, abs(val));
		}
		printf("#%d %d %d\n", i, up, down);
	}
	return 0;
}