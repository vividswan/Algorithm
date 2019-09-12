#include <stdio.h>
#include <string.h>
int main(void) {
	int task;
	char str[105];
	int arr[100] = { 0, };
	scanf("%d", &task);
	int count;
	int num = 0;
	int result = 0;
	for (int d = 1; task >= d; d++) {
		scanf("%s", str);
		count = strlen(str);
		for (int a = 0; count > a; a++) {
			if (a == 0) {
				arr[str[a] - 'a']++;
				continue;
			}
			else if (str[a - 1] == str[a]) continue;
			else arr[str[a] - 'a']++;
		}
		for (int c = 0; 26 > c; c++) {
			if (arr[c] >= 2) result++;
		}
		if (result == 0) num++;
		result = 0;
		for (int b = 0; 26 >= b; b++)  arr[b] = 0;
	}
	printf("%d", num);
	return 0;
}