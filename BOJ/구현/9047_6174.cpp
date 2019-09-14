#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(void) {
	int roof;
	cin >> roof;
	for (int i = 0; i < roof; i++) {
		int num;
		cin >> num;
		int cnt = 0;
		while (num != 6174) {
			int arr[5];
			arr[0] = num / 1000;
			arr[1] = (num % 1000) / 100;
			arr[2] = (num % 100) / 10;
			arr[3] = num % 10;
			sort(arr, arr + 4);
			int b_num = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];
			int s_num = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
			num = b_num - s_num;
			cnt++;
		}
		printf("%d\n", cnt);
	}
}