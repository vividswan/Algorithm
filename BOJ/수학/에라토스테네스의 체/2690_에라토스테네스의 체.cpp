#include <iostream>
using namespace std;
int num, cnt, arr[1010];
int main(void) {
	cin >> num >> cnt;
	for (int i = 2; i <= num; i++) {
		arr[i] = i;
	}
	int min;
	int min_x;
	int mul;
	int j = 2;
	int res = 0;
	while (1) {
		mul = 1;
		for (j = 2; j <= num; j++) {
			if (arr[j] != 0) {
				min = j;
				break;
			}
		}
		min_x = mul * min;
		while (min_x <= num) {
			if (arr[min_x] != 0) {
				arr[min_x] = 0;
				res++;
				if (res == cnt) {
					printf("%d", min_x);
					return 0;
				}
				mul++;
				min_x = mul * min;
			}
			else if (arr[min_x] == 0) {
				mul++;
				min_x = mul * min;
			}
		}
	}
}