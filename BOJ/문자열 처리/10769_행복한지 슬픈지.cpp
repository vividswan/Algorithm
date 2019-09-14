#include <stdio.h>
#include <string.h>
int main(void) {
	char str[230];
	scanf("%[^\n]s", str);
	int len = strlen(str);
	int happy = 0;
	int sad = 0;
	for (int a = 0; len > a; a++) {
		if (str[a] == ':' && str[a + 1] == '-' && str[a + 2] == ')') happy++;
		else if (str[a] == ':' && str[a + 1] == '-' && str[a + 2] == '(') sad++;
	}
	if (happy == 0 && sad == 0) printf("none");
	else if (happy == sad) printf("unsure");
	else if (happy > sad) printf("happy");
	else if (happy < sad) printf("sad");
	return 0;
}
