#include <stdio.h>
#include <string.h>
int main(void) {
	char str[1000005];
	scanf("%[^\n]s", str);
	int num = 0;
	int count = strlen(str);
	for (int a = 0; count > a; a++) {
		if (a == 0) {
			if (65 <= str[a] && str[a] <= 90) num++;
			else if (97 <= str[a] && str[a] <= 122) num++;
			else continue;
		}
		else if (str[a - 1] == ' ') {
			if (65 <= str[a] && str[a] <= 90) num++;
			else if (97 <= str[a] && str[a] <= 122) num++;
			else continue;
		}
	}
	printf("%d", num);
	return 0;
}