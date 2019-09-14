#include <iostream>
#include <cstring>
using namespace std;
int n;
int arr[14], res[14];
void go(int index, int cnt);
int main(void) {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		go(0, 0);
		printf("\n");
	}
	return 0;
}
void go(int index, int cnt) {
	if (index == 6) {
		for (int i = 0; i < 6; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
		return;
	}
	for (int i = cnt; i < n; i++) {
		res[index] = arr[i];
		go(index + 1, i + 1);
	}
}