#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
	int roof;
	char str[35];
	scanf("%d ", &roof);
	int i;
	for (i = 1; i <= roof; i++) {
		gets(str);
		str[0] = toupper(str[0]);
		puts(str);
	}
	return 0;
}