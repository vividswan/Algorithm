#include <iostream>
#include <cstring>
using namespace std;
int main(void) {
	int t;
	scanf("%d", &t);
	while (t--) {
		char str[27];
		scanf("%s", str);
		int length = strlen(str);
		if (length == 1) {
			printf("%c\n%c\n", str[0], str[0]);
			continue;
		}
		if (length % 2 == 0) {
			for (int i = 0; i < length; i += 2) printf("%c", str[i]);
			printf("\n");
			for (int i = 1; i < length; i += 2) printf("%c", str[i]);
			printf("\n");
		}
		else {
			for (int i = 0; i < length; i += 2) printf("%c", str[i]);
			for (int i = 1; i < length; i += 2) printf("%c", str[i]);
			printf("\n");
			for (int i = 1; i < length; i += 2) printf("%c", str[i]);
			for (int i = 0; i < length; i += 2) printf("%c", str[i]);
			printf("\n");
		}
	}
	return 0;
}