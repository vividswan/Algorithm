#include <iostream>
using namespace std;
int arr[1002], per[1002], ex_per[1002];
int main(void) {
	int tot, lot;
	cin >> tot;
	cin >> lot;
	for (int i = 1; i <= lot; i++) {
		int a, b;
		cin >> a >> b;
		ex_per[i] = b - a + 1;
		for (int j = a; j <= b; j++) {
			if (arr[j] == 0) {
				per[i]++;
				arr[j] = 1;
			}
		}
	}
	int ex_max = 0;
	for (int i = 1; i <= lot; i++) {
		if (ex_max < ex_per[i]) ex_max = ex_per[i];
	}
	for (int i = 1; i <= lot; i++) {
		if (ex_max == ex_per[i]) {
			cout << i << '\n';
			break;
		}
	}
	int max = 0;
	for (int i = 1; i <= lot; i++) {
		if (max < per[i]) max = per[i];
	}
	for (int i = 1; i <= lot; i++) {
		if (max == per[i]) {
			cout << i;
			break;
		}
	}
	return 0;
}