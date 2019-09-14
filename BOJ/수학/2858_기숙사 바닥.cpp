#include <stdio.h>
int main(void) {
	int red, brn, cnt;
	scanf("%d %d", &red, &brn);
	for (cnt = 1; cnt <= brn; cnt++) {
		if (brn % cnt == 0) {
			if (red == 4 + 2 * cnt + 2 * (brn / cnt)) {
				if ((brn / cnt) + 2 > cnt + 2) {
					printf("%d %d", (brn / cnt) + 2, cnt + 2);
				}
				else printf("%d %d", cnt + 2, (brn / cnt) + 2);
				break;
			}
		}
	}
	return 0;
}