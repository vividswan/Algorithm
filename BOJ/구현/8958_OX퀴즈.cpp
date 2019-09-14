#include <stdio.h>
int main(void) {
	int roof;
	int grade = 0;
	int plus = 0;
	scanf("%d", &roof);
	for (int a = 1; roof >= a; a++) {
		char str[80];
		scanf("%s", str);
		for (int a = 0; 80 >= a; a++) {
			if (str[a] == 'O') {
				plus++;
				grade += plus;
			}
			else if (str[a] == 'X') plus = 0;
			else break;
		}
		printf("%d\n", grade);
		grade = 0;
		plus = 0;
	}
}