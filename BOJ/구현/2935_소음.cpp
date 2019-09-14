#include<stdio.h>
#include<string.h>
int main(void) {
	char str1[210];
	char str2[210];
	char a;
	scanf("%s ", str1);
	scanf("%c ", &a);
	scanf("%s ", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (a == '*') {
		for (int b = len1; (len1 + len2) - 1 > b; b++) str1[b] = '0';
		printf("%s", str1);
	}
	else if (a == '+') {
		if (len1 == len2) {
			str1[0] = '2';
			printf("%s", str1);
		}
		else if (len1 > len2) {
			str1[len1 - len2] = '1';
			printf("%s", str1);
		}
		else if (len2 > len1) {
			str2[len2 - len1] = '1';
			printf("%s", str2);
		}
	}
	return 0;
}