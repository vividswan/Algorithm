#include <iostream>
using namespace std;
long long arr[4];
long long now[4];
int main(void) {
	for (int i = 1; i <= 3; i++) scanf("%lld %lld", &arr[i], &now[i]);
	int cnt = 1;
	int n = 100;
	while (n--) {
		if (cnt != 3) {
			if (now[cnt] + now[cnt + 1] <= arr[cnt + 1]) {
				now[cnt + 1] += now[cnt];
				now[cnt] = 0;
			}
			else {
				now[cnt] -= (arr[cnt + 1] - now[cnt + 1]);
				now[cnt + 1] = arr[cnt + 1];
			}
			cnt++;
		}
		else if (cnt == 3) {
			if (now[3] + now[1] <= arr[1]) {
				now[1] += now[3];
				now[3] = 0;
			}
			else {
				now[3] -= (arr[1] - now[1]);
				now[1] = arr[1];
			}
			cnt = 1;
		}
	}
	printf("%lld\n%lld\n%lld\n", now[1], now[2], now[3]);
}