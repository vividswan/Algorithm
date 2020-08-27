#include <iostream>
using namespace std;
int main(void) {
	char str[101];
	int arr[11] = { 0,};
	cin >> str;
	for (int i = 0; str[i] != '\0'; i++) {
		int now = str[i] - '0';
		arr[now]++;
	}
	int result = 0;
	int maxValue = 0;
	for (int i = 0; i < 10; i++) {
		if (maxValue <= arr[i]) {
			result = i;
			maxValue = arr[i];
		}
	}
	cout << result << '\n';
	return 0;
}