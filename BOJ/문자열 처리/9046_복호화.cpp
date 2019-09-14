#include <stdio.h>
#include <string.h>
int main(void) {
	int roof;
	int roof1 = 0;
	char str[260];
	int arr[30] = { 0, };
	int count;
	int d;
	scanf("%d ", &roof);
	for (roof1; roof > roof1; roof1++) {
		gets(str);
		count = strlen(str);
		for (int b = 0; count > b; b++) {
			if (str[b] == ' ') continue;
			else arr[str[b] - 'a']++;
		}
		int result = 0;
		int result2;
		for (int c = 0; 30 > c; c++) {
			if (arr[c] > result) {
				result = arr[c];
				result2 = c;
			}
		}
		d = 0;
		for (int c = 0; 29 > c; c++) {
			if (result == arr[c]) d++;
		}
		if (d > 1) printf("?\n");
		else if (d = 1) printf("%c\n", result2 + 'a');
		for (int a = 0; 30 > a; a++) arr[a] = 0;
	}
	return 0;
}
