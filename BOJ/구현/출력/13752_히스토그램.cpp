#include <stdio.h>
int main(void) {
	int roof;
	int arr[105];
	scanf("%d", &roof);
	for (int a = 0; roof > a; a++) {
		scanf("%d", &arr[a]);
	}
	for (int a = 0; roof > a; a++) {
		for (int b = 0; arr[a] > b; b++) printf("=");
		printf("\n");
	}
	return 0;
}