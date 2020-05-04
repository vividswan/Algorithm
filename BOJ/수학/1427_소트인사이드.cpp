#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int main(void) {
	char str[15];
	vector<int> arr;
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		arr.push_back(str[i] - '0');
	}
	sort(arr.begin(), arr.end());
	for (int i = arr.size()-1; i >= 0; i--) {
		printf("%d", arr[i]);
	}
	printf("\n");
	return 0;
}