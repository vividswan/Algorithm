#include <stdio.h>
int main(void) {
	int roof1, roof2, roof3, cnt, result, sel1, sel2;
	int arr[1036];
	roof3 = 0;
	result = 0;
	cnt = 45;
	for (roof1 = 1; cnt >= roof1; roof1++) {
		for (roof2 = 1; roof1 >= roof2; roof2++) {
			roof3 += 1;
			arr[roof3] = roof1;
		}
	}
	scanf("%d %d", &sel1, &sel2);
	for (sel1; sel2 >= sel1; sel1++) result += arr[sel1];
	printf("%d", result);
	return 0;
}