#include <iostream>
using namespace std;
int main(void) {
	int arr[4];
	int sum;
	for (int i = 1; i <= 3; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d", &sum);
	for (int i = 0; i * arr[1] <= sum; i++) {
		for (int j = 0; j * arr[2] <= sum; j++) {
			for (int k = 0; k * arr[3] <= sum; k++) {
				if (sum == i * arr[1] + j * arr[2] + k * arr[3]) {
					printf("1");
					return 0;
				}
			}
		}
	}
	printf("0");
	return 0;
}