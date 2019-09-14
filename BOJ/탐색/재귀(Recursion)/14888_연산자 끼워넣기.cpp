#include <iostream>
using namespace std;
int roof, arr[12], sub[5];
void dfs(int res, int count);
int max1 = -1000000000, min1 = 1000000000;
int main(void) {
	cin >> roof;
	for (int i = 0; i < roof; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> sub[i];
	}
	dfs(arr[0], 0);
	printf("%d\n%d", max1, min1);
}
void dfs(int res, int count) {
	if (count == roof - 1) {
		if (res < min1) min1 = res;
		if (res > max1) max1 = res;
		return;
	}
	if (sub[0] > 0) {
		sub[0]--;
		dfs(res + arr[count + 1], count + 1);
		sub[0]++;
	}
	if (sub[1] > 0) {
		sub[1]--;
		dfs(res - arr[count + 1], count + 1);
		sub[1]++;
	}
	if (sub[2] > 0) {
		sub[2]--;
		dfs(res * arr[count + 1], count + 1);
		sub[2]++;
	}
	if (sub[3] > 0) {
		sub[3]--;
		dfs(res / arr[count + 1], count + 1);
		sub[3]++;
	}
}