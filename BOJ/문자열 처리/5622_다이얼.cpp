#include <stdio.h>
#include <string.h>
int main(void) {
	char str[20];
	int arr[26] = { 3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10 };
	int result = 0;
	int count;
	scanf("%s", str);
	count = strlen(str);
	for (int a = 0; count > a; a++) {
		result += arr[str[a] - 65];
	}
	printf("%d", result);
}