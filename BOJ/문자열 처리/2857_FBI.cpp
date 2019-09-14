#include <stdio.h>
#include <string.h>
int main(void) {
	char str[5][15];
	int arr[5] = { 0, };
	int i, j;
	for (i = 0; i < 5; i++) gets(str[i]);
	for (i = 0; i < 5; i++) {
		for (j = 0; j < strlen(str[i]); j++) if (str[i][j] == 'F' && str[i][j + 1] == 'B' && str[i][j + 2] == 'I') arr[i]++;
	}
	if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0 && arr[3] == 0 && arr[4] == 0) printf("""HE GOT AWAY!""");
	else for (i = 0; i < 5; i++) if (arr[i] > 0) printf("%d ", i + 1);
}