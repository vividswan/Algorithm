#include<stdio.h>
#include <string.h>
int main(void) {
	char str[10005];
	int ioi = 0;
	int joi = 0;
	scanf("%s", str);
	int count = strlen(str);
	for (int a = 0; count > a; a++) {
		if (str[a] == 'J' && str[a + 1] == 'O' && str[a + 2] == 'I') joi++;
		else if (str[a] == 'I' && str[a + 1] == 'O' && str[a + 2] == 'I') ioi++;
	}
	printf("%d\n%d", joi, ioi);
	return 0;
}