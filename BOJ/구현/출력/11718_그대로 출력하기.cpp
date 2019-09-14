#include <stdio.h>
char bef = 'a';
int main(void) {
	while (1) {
		char a;
		scanf("%c", &a);
		if (a == '\n' && bef == '\n') return 0;
		else {
			printf("%c", a);
			bef = a;
		}
	}
}