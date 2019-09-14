#include <stdio.h>
#include <string.h>
int main() {
	int num, i;
	scanf("%d ", &num);
	for (i = 0; i < num; i++) {
		char str[100];
		gets(str);
		int j;
		for (j = 0; j < strlen(str); j++) {
			if (str[j] == ' ') break;
		}
		j++;
		char str2[120] = "god";
		int k;
		for (k = 3; j < strlen(str); j++, k++) {
			if (str[j] == ' ') {
				k--;
				continue;
			}
			str2[k] = str[j];
		}
		printf("%s\n", str2);
	}
}