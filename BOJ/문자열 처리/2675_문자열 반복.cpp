#include <stdio.h>
int main(void) {
	int num, roof;
	int num2;
	char str[25];
	scanf("%d", &num);
	for (int a = 1; num >= a; a++) {
		scanf("%d %s", &roof, str);
		for (num2 = 0; 24 >= num2; num2++) {
			if (str[num2] ^= '\0') for (int b = 1; roof >= b; b++) printf("%c", str[num2]);
			else if (str[num2] == '\0') break;
		}
		printf("\n");
	}
}