#include <iostream>
#include <cstring>
using namespace std;
char str[101];
int main(void) {
	int idx = 0;
	while (1) {
		scanf("%c", &str[idx]);
		if (str[idx] == '\n') {
			str[idx] = '\0';
			break;
		}
		idx++;
	}
	for (int i = 0; i < strlen(str); i++) {
		if ('a' <= str[i] && str[i] <= 'z') {
			int value = str[i];
			if (value + 13 > 'z') {
				value = value + 13 - 'z' - 1;
				str[i] = value+'a';
			}
			else str[i] += 13;
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			int value = str[i];
			if (value + 13 > 'Z') {
				value = value + 13 - 'Z' - 1;
				str[i] = value+'A';
			}
			else str[i] += 13;
		}
	}
	printf("%s\n", str);
}