#include <iostream>
using namespace std;
int swc;
int main(void) {
	int val;
	scanf("%d", &val);
	for (int i = 1; i <= val; i++) {
		int res = i;
		int nowVal = i;
		while (nowVal) {
			res += nowVal % 10;
			nowVal /= 10;
		}
		if (res == val) {
			swc = i;
			break;
		}
	}
	printf("%d\n", swc);
	return 0;
}