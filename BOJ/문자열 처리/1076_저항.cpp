#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char str[][20] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };
int main(void) {
	long long num = 0;
	char color[20];
	scanf("%s", color);
	for (int i = 0; i < 10; i++) {
		if (!strcmp(str[i], color)) {
			num += 10 * i;
			break;
		}
	}
	scanf("%s", color);
	for (int i = 0; i < 10; i++) {
		if (!strcmp(str[i], color)) {
			num += i;
			break;
		}
	}
	scanf("%s", color);
	for (int i = 0; i < 10; i++) {
		if (!strcmp(str[i], color)) {
			num *= pow(10, i);
			break;
		}
	}
	printf("%lld\n", num);
	return 0;
}