#include <iostream>
#include <cstring>
using namespace std;
char a[10], b[10], c[10];
int x = 0, y = 0;
int main(void) {
	scanf("%s %s %s", a, b, c);
	if (a[0] == 't') x = 1;
	if (c[0] == 't') y = 1;
	if (b[0] == 'A') {
		if (x && y) printf("true");
		else printf("false");
	}
	else {
		if (x || y) printf("true");
		else printf("false");
	}
}