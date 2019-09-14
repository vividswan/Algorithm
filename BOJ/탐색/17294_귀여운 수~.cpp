#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
char qu[19];
int main(void) {
	scanf(" %s", qu);
	int len = strlen(qu);
	if (len == 1 || len == 2) {
		printf("?(?????)?..¡Æ¢½ ²î¿ä¹Ì!!");
		return 0;
	}
	int st = qu[0] - qu[1];
	int swc = 0;
	for (int i = 1; i < len - 1; i++) {
		int now = qu[i] - qu[i + 1];
		if (st != now) {
			swc++;
			break;
		}
	}
	if (swc) printf("ÈïÄ©»×!! <(£þ ? £þ)>");
	else printf("?(?????)?..¡Æ¢½ ²î¿ä¹Ì!!");
}