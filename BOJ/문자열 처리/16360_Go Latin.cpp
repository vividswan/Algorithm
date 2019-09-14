#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main(void) {
	int tk;
	scanf("%d", &tk);
	getchar();
	for (int i = 1; i <= tk; i++) {
		char str[25];
		scanf("%s", str);
		int len = strlen(str);
		if (str[len - 1] == 'a') {
			strcat(str, "s\0");
		}
		else if (str[len - 1] == 'i' || str[len - 1] == 'y') {
			str[len - 1] = 'i';
			strcat(str, "os\0");
		}
		else if (str[len - 1] == 'l') {
			strcat(str, "es\0");
		}
		else if (str[len - 1] == 'n') {
			str[len - 1] = 'a';
			strcat(str, "nes\0");
		}
		else if (str[len - 2] == 'n' && str[len - 1] == 'e') {
			str[len - 2] = 'a';
			str[len - 1] = 'n';
			strcat(str, "es\0");
		}
		else if (str[len - 1] == 'o') {
			strcat(str, "s\0");
		}
		else if (str[len - 1] == 'r') {
			strcat(str, "es\0");
		}
		else if (str[len - 1] == 't') {
			strcat(str, "as\0");
		}
		else if (str[len - 1] == 'u') {
			strcat(str, "s\0");
		}
		else if (str[len - 1] == 'v') {
			strcat(str, "es\0");
		}
		else if (str[len - 1] == 'w') {
			strcat(str, "as\0");
		}
		else strcat(str, "us\0");
		printf("%s\n", str);
	}
}