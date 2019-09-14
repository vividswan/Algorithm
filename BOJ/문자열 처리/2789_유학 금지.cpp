#include <stdio.h>
#include <string.h>
int main(void) {
	char str1[105];
	char str2[105];
	int count;
	int roof1 = 0;
	int roof2 = 0;
	scanf("%s", str1);
	count = strlen(str1);
	for (int a = 0; count > a; a++) {
		if (str1[a] == 67 || str1[a] == 65 || str1[a] == 77 || str1[a] == 66 || str1[a] == 82 || str1[a] == 73 || str1[a] == 68 || str1[a] == 71 || str1[a] == 69) str1[a] = '\0';
	}
	for (int a = 0; count >= a; a++) if (str1[a] ^= '\0') printf("%c", str1[a]);
	return 0;
}