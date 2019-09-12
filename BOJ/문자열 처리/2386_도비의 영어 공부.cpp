#include <stdio.h>
#include <string.h>
int main(void) {
	while (1) {
		char sen[290];
		gets(sen);
		if (sen[0] == '#') break;
		else {
			int i = 1;
			int result = 0;
			for (i; i < strlen(sen); i++) {
				if (sen[0] == sen[i] || sen[i] == sen[0] - 32 || sen[i] == sen[0] + 32) result++;
			}
			printf("%c %d\n", sen[0], result);
		}
	}
	return 0;
}