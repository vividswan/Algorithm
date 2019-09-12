#include <iostream>
using namespace std;
int n, arr[51], a, b;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) printf("A\n", arr[1]);
	else if (n == 2) {
		if (arr[1] == arr[2]) printf("%d\n", arr[1]);
		else printf("A\n");
	}
	else {
		if (arr[1] == arr[2] && arr[2] != arr[3]) printf("B\n");
		else {
			if (arr[1] == arr[2] && arr[2] == arr[3]) {
				a = 1;
				b = 0;
			}
			else {
				a = ((arr[2] - arr[3]) / (arr[1] - arr[2]));
				b = arr[2] - (a * arr[1]);
			}
			for (int i = 1; i <= n - 1; i++) {
				if (arr[i + 1] != (a * arr[i]) + b) {
					printf("B\n");
					return 0;
				}
			}
			printf("%d\n", arr[n] * a + b);
		}
	}
}