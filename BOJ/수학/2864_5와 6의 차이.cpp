#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	char str1[8], str2[8];
	scanf("%s %s", str1, str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (int i = 0; i < len1; i++) {
		if (str1[i] == '5') str1[i] = '6';
	}
	for (int i = 0; i < len2; i++) {
		if (str2[i] == '5') str2[i] = '6';
	}
	int res_max = atoi(str1) + atoi(str2);
	for (int i = 0; i < len1; i++) {
		if (str1[i] == '6') str1[i] = '5';
	}
	for (int i = 0; i < len2; i++) {
		if (str2[i] == '6') str2[i] = '5';
	}
	int res_min = atoi(str1) + atoi(str2);
	printf("%d %d", res_min, res_max);
}