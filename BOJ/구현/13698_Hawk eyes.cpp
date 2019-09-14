#include <stdio.h>
#include <string.h>
int main(void) {
	int arr[4] = { -1,0,0,1 };
	int temp, a;
	char str[205];
	gets(str);
	for (a = 0; a < strlen(str); a++) {
		if (str[a] == 'A') {
			temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
		else if (str[a] == 'B') {
			temp = arr[0];
			arr[0] = arr[2];
			arr[2] = temp;
		}
		else if (str[a] == 'C') {
			temp = arr[0];
			arr[0] = arr[3];
			arr[3] = temp;
		}
		else if (str[a] == 'D') {
			temp = arr[1];
			arr[1] = arr[2];
			arr[2] = temp;
		}
		else if (str[a] == 'E') {
			temp = arr[1];
			arr[1] = arr[3];
			arr[3] = temp;
		}
		else if (str[a] == 'F') {
			temp = arr[2];
			arr[2] = arr[3];
			arr[3] = temp;
		}
	}
	int i;
	for (i = 0; i < 4; i++) if (arr[i] == -1) printf("%d\n", i + 1);
	for (i = 0; i < 4; i++) if (arr[i] == 1) printf("%d\n", i + 1);
	return 0;
}