#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
char str[31];
int main(void) {
	scanf("%s", str);
	int z_level = strlen(str);
	int q_key = atoi(str);
	int x = 0, y = 0;
	for (int i = 0; i < z_level; i++) {
		int a = z_level - i;
		int b = 1;
		for (int i = 1; i <= a; i++) {
			b *= 2;
		}
		if (str[i] == '0') {
			continue;
		}
		if (str[i] == '1') {
			x += (b / 2);
		}
		if (str[i] == '2') {
			y += (b / 2);
		}
		if (str[i] == '3') {
			x += (b / 2);
			y += (b / 2);
		}
	}
	printf("%d %d %d\n", z_level, x, y);
}