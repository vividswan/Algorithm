#include <stdio.h>
#include <string.h>
int main(void) {
	int roof;
	scanf("%d", &roof);
	for (int a = 0; roof > a; a++) {
		char str1[25], str2[25];
		scanf("%s %s", str1, str2);
		int count = strlen(str1);
		printf("Distances:");
		for (int a = 0; count > a; a++) {
			if (str2[a] >= str1[a]) printf(" %d", str2[a] - str1[a]);
			else printf(" %d", (str2[a] + 26) - str1[a]);
		}
		printf("\n");
	}
	return 0;
}