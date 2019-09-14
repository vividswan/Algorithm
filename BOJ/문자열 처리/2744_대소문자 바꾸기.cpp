#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
	char str[105];
	gets(str);
	int i;
	for (i = 0; i < strlen(str); i++) {
		if ('a' <= str[i] && str[i] <= 'z') str[i] = toupper(str[i]);
		else if ('A' <= str[i] && str[i] <= 'Z') str[i] = tolower(str[i]);
	}
	printf(str);
	return 0;
}