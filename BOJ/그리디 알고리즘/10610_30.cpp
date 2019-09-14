#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(void) {
	char str[100001];
	scanf("%s", str);
	int cnt = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '0') cnt++;
		if (cnt == 1) break;
	}
	if (cnt == 0) {
		printf("-1");
		return 0;
	}
	int sum = 0;
	int arr[100001];
	for (int i = 0; i < strlen(str); i++) {
		sum += str[i] - '0';
		arr[i] = str[i] - '0';
	}
	if (sum % 3) {
		printf("-1");
		return 0;
	}
	else {
		sort(arr, arr + strlen(str) + 1);
		for (int i = strlen(str); i > 0; i--) {
			printf("%d", arr[i]);
		}
	}
}