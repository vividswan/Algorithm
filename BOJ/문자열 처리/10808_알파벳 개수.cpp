#include <iostream>
#include <cstring>
using namespace std;
int arr[30];
int main(void) {
	char str[101];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		int idx = str[i] - 'a';
		arr[idx]++;
	}
	int totalApb = 'z' - 'a' + 1;
	for (int i = 0; i < totalApb; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}