#include<stdio.h>
int main(void) {
	int roof1, roof2, roof4;
	int roof3 = 7;
	int sum = 0;
	int main_16[17];
	for (roof1 = 1; 8 >= roof1; roof1++) scanf("%d", &main_16[roof1]);
	for (roof1 = 1; 8 >= roof1; roof1++) main_16[roof1 + 8] = main_16[roof1];
	for (roof3; roof3; roof3--) {
		for (roof1 = 1; roof3 >= roof1; roof1++) {
			if (main_16[roof1 + 8] > main_16[roof1 + 9]) {
				roof4 = main_16[roof1 + 9];
				main_16[roof1 + 9] = main_16[roof1 + 8];
				main_16[roof1 + 8] = roof4;
			}
		}
	}
	for (roof1 = 1; 8 >= roof1; roof1++) if (main_16[roof1] == main_16[9] || main_16[roof1] == main_16[10] || main_16[roof1] == main_16[11]) main_16[roof1] = 151;
	for (roof1 = 1; 8 >= roof1; roof1++) {
		if (main_16[roof1] == 151) continue;
		else sum += main_16[roof1];
	}
	printf("%d\n", sum);
	for (roof1 = 1; 8 >= roof1; roof1++) {
		if (main_16[roof1] == 151) continue;
		else printf("%d", roof1);
		if (roof1 == 8) break;
		else printf(" ");
	}
}