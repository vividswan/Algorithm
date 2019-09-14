#include <iostream>
#include <cstring>
using namespace std;
char a[31], b[31], h[31][31];
int main(void) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			h[i][j] = '.';
		}
	}
	scanf("%s %s", a, b);
	int c = strlen(a);
	int d = strlen(b);
	int e, f, g = 0;
	for (int i = 0; i < c; i++) {
		if (g != 0) break;
		for (int j = 0; j < d; j++) {
			if (a[i] == b[j]) {
				e = i;
				f = j;
				g++;
				break;
			}
		}
	}
	for (int i = 0; i < c; i++) {
		h[f][i] = a[i];
	}
	for (int i = 0; i < d; i++) {
		h[i][e] = b[i];
	}
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			printf("%c", h[i][j]);
		}
		printf("\n");
	}
}