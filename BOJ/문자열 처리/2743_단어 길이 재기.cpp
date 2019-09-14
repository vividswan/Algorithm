#include <stdio.h>
#include <string.h>
int main(void) {
	char str[105];
	gets(str);
	printf("%d", strlen(str));
	return 0;
}