#include <iostream>
#include <algorithm>
using namespace std;
int n, m, c;
int arr[111111];
int le = 0;
int ri = 1000000000;
int go(int mid);
int main(void) {
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n);
	while (le <= ri) {
		int mid = (le + ri) / 2;
		if (go(mid)) ri = mid - 1;
		else le = mid + 1;
	}
	printf("%d\n", le);
}
int go(int mid) {
	int cnt = 1;
	for (int i = 1, st = 0; i < n; i++) {
		if (i - st < c && arr[i] <= arr[st] + mid) continue;
		cnt += 1;
		st = i;
	}
	if (cnt <= m) return 1;
	else return 0;
}