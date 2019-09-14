#include <stdio.h>
int main(void) {
	int roof, same, differnt;
	int num;
	int arr[1005];
	int arr2[1005];
	scanf("%d ", &num);
	for (int a = 0; num > a; a++) {
		scanf("%d", &arr[a]);
	}
	for (roof = 0; 10000 >= roof; roof++) {
		same = 0;
		differnt = 0;
		for (int d = 0; num > d; d++) arr2[d] = 1;
		for (int b = 0; num > b; b++) {
			if (arr[b] > roof) {
				same++;
				arr2[b] = 0;
			}
		}
		if (same > roof || same < roof) {
			for (int b = 0; num > b; b++) {
				if (arr[b] == roof && arr2[b] == 1) {
					same++;
					arr2[b] = 0;
				}
				if (same == roof) break;
			}
		}
		if (same == roof) {
			for (int b = 0; num > b; b++) {
				if (arr2[b] == 1 && arr[b] <= roof) differnt++;
			}
			if (num == (same + differnt)) break;
		}
	}
	printf("%d", roof);
	return 0;
}