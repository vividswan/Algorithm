#include <iostream>
using namespace std;
int arr[7], sum, mnm = 100, cnt;
int main(void) {
	for (int i = 0; i < 7; i++) {
		int num;
		cin >> num;
		if (num & 2 != 0) {
			arr[i] = num;
			sum += num;
			if (mnm > num) mnm = num;
			cnt++;
		}
	}
	if (cnt > 0) cout << sum << '\n' << mnm;
	else cout << -1;
	return 0;
}