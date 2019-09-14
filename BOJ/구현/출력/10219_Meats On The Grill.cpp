#include <stdio.h>
using namespace std;
char str[12][12];
int main() {
	int roof;
	scanf("%d", &roof);
	for (int i = 1; i <= roof; i++) {
		int n, m;
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", str[i]);
		}
		for (int i = n; i >= 1; i--) {
			printf("%s\n", str[i]);
		}
	}
}