#include <iostream>
#include <algorithm>
using namespace std;
int arr[10];
int maxx, max_idx;
int main(void) {
	for (int i = 1; i <= 9; i++) {
		scanf("%d", &arr[i]);
		if (maxx < arr[i]) {
			maxx = arr[i];
			max_idx = i;
		}
	}
	printf("%d\n%d\n", maxx, max_idx);
}