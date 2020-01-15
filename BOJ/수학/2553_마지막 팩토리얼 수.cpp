#include<iostream>
using namespace std;
int arr[20001];
int main(void) {
	int n;
	arr[1] = 1;
	for (int i = 2; i <= 20000; i++) {
		int now = arr[i - 1];
		now *= i;
		while (1) {
			if (now % 10) {
				now %= 100000;
				arr[i] = now;
				break;
			}
			else now /= 10;
		}
	}
	scanf("%d", &n);
	printf("%d\n", arr[n]%10);
	return 0;
}