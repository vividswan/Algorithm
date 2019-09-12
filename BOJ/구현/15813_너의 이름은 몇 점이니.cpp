#include <iostream>
#include <cstring>
using namespace std;
char str[101];
int n;
int res;
int main(void) {
	scanf("%d", &n);
	scanf(" %s", str);
	for (int i = 0; i < n; i++) {
		res += str[i] - 'A' + 1;
	}
	printf("%d\n", res);
}