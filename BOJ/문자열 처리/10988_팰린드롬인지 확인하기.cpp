#include <iostream>
#include <cstring>
using namespace std;
char str[101];
bool res;
int main(void) {
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] != str[strlen(str) - 1 - i]) {
			res = false;
			break;
		}
		if (i == strlen(str)-1) {
			res = true;
		}
	}
	if (res) printf("1\n");
	else printf("0\n");
	return 0;
}