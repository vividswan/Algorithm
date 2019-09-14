#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int i = 0; i < roof; i++) {
		int n;
		scanf("%d", &n);
		int arr[10001] = { 0, };
		int res[10001] = { 0, };
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + n + 1);
		int cnt = n;
		int st = n / 2 + 1;
		int go = st + 1;
		int back = st - 1;
		while (cnt) {
			if (cnt == n) {
				res[st] = arr[cnt];
			}
			else if (cnt % 2) {
				if (go == n + 1) go = 1;
				res[go] = arr[cnt];
				go++;
			}
			else {
				if (back == 0) back = n;
				res[back] = arr[cnt];
				back--;
			}
			cnt--;
		}
		int ed = 0;
		for (int i = 1; i <= n; i++) {
			if (i == n) {
				ed = max(abs(res[i] - res[1]), ed);
				break;
			}
			ed = max(abs(res[i] - res[i + 1]), ed);
		}
		printf("%d\n", ed);
	}
	return 0;
}