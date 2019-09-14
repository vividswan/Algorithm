#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, rev[101];
int arr1[101], arr2[101], arr3[101];
char str[101][9];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		rev[i] = a;
	}
	for (int i = 1; i <= n; i++) {
		scanf(" %s", str[i]);
	}
	for (int i = 1; i <= n; i++) {
		arr1[i] = rev[i];
	}
	for (int i = 1; i <= n; i++) {
		arr2[i] = arr1[rev[i]];
	}
	for (int i = 1; i <= n; i++) {
		arr3[i] = arr2[rev[i]];
	}
	for (int i = 1; i <= n; i++) {
		printf("%s\n", str[arr3[i]]);
	}
	return 0;
}