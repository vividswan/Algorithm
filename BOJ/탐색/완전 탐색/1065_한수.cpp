#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cnt;
int main() {
	char str[5];
	scanf("%s", str);
	int i;
	int num = atoi(str);
	if (num == 1000) {
		str[0] = 9;
		str[1] = 9;
		str[2] = 9;
		str[3] = '\0';
		num = 999;
	}
	if (num < 100) {
		printf("%d", num);
		return 0;
	}
	else {
		cnt += 99;
		for (i = 100; i <= num; i++) {
			if (i / 100 - (i / 10) % 10 == (i / 10) % 10 - i % 10) cnt++;
		}
		printf("%d", cnt);
	}
	return 0;
}