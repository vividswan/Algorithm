#include <stdio.h>
int main(void) {
	int arr[26] = { 0, };
	while (1) {
		char a = 0;
		scanf("%c", &a);
		if (a == 0) break;
		if (a >= 'a' && a <= 'z') arr[a - 'a']++;
	}
	int max = 0;
	for (int b = 0; 26 > b; b++) {
		if (max < arr[b]) max = arr[b];
	}
	for (int b = 0; 26 > b; b++) {
		if (max == arr[b]) printf("%c", b + 'a');
	}
	return 0;
}