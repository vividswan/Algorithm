#include <stdio.h>
int main(void) {
	int a = 0;
	char i;
	while (1) {
		scanf("%c", &i);
		if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u' || i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U') a++;
		else if (i == '\n') {
			printf("%d\n", a);
			a = 0;
		}
		else if (i == '#') break;
	}
}