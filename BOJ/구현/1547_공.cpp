#include <stdio.h>
int main(void) {
	int roof;
	int j, k, temp;
	int arr[3] = { 1,2,3 };
	scanf("%d", &roof);
	for (int i = 1; i <= roof; i++) {
		scanf("%d %d", &j, &k);
		temp = arr[j - 1];
		arr[j - 1] = arr[k - 1];
		arr[k - 1] = temp;
	}
	for (int l = 0; l < 3; l++) if (arr[l] == 1) printf("%d", l + 1);
	return 0;
}