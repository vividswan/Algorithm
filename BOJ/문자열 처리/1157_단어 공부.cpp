#include <stdio.h>
int main(void) {
	int num, num2, roof;
	char str[1000010];
	int arr[30] = { 0, };
	scanf("%s", str);
	for (int a = 0; 1000009 >= a; a++) {
		if (str[a] == '\0') break;
		else for (num = 0; 29 >= num; num++) {
			if (str[a] == 65 + num || str[a] == 97 + num) arr[num]++;
		}
	}
	int max = arr[0];
	for (int a = 1; 29 >= a; a++) {
		if (arr[a] > max) max = arr[a];
	}
	int num3 = 0;
	for (int a = 0; 29 >= a; a++) if (max == arr[a]) num3++;
	int result;
	if (num3 >= 2) printf("?");
	else if (num3 == 1) for (result = 0; 25 >= result; result++) if (max == arr[result]) printf("%c", 65 + result);
	return 0;
}