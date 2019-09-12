#include <stdio.h>
int main(void) {
	int arr[30] = { 0, };
	int task;
	char str[35];
	int num = 0;
	scanf("%d ", &task);
	for (int c = 1; task >= c; c++) {
		scanf("%s ", str);
		arr[str[0] - 'a']++;
	}
	for (int b = 0; 30 > b; b++) {
		if (arr[b] >= 5) num++;
	}
	if (num == 0) printf("PREDAJA");
	else if (num >= 1) {
		for (int b = 0; 30 > b; b++) {
			if (arr[b] >= 5) printf("%c", b + 'a');
		}
	}
	return 0;
}
