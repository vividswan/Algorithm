#include <iostream>
using namespace std;
void hanoi(int now, int go, int ed);
long double cnt(int now);
int main(void) {
	int now;
	cin >> now;
	printf("%.0Lf\n", cnt(now));
	if (now <= 20) hanoi(now, 1, 3);
	return 0;
}
void hanoi(int now, int go, int ed) {
	if (now > 1) {
		int mid;
		if (go == 1 && ed == 2) mid = 3;
		else if (go == 1 && ed == 3) mid = 2;
		else if (go == 2 && ed == 3) mid = 1;
		else if (go == 2 && ed == 1) mid = 3;
		else if (go == 3 && ed == 1) mid = 2;
		else if (go == 3 && ed == 2) mid = 1;
		hanoi(now - 1, go, mid);
		cout << go << ' ' << ed << "\n";
		hanoi(now - 1, mid, ed);
	}
	else if (now == 1) {
		cout << go << ' ' << ed << "\n";
		return;
	}

}
long double cnt(int now) {
	long double res = 1;
	for (int i = 2; i <= now; i++) {
		res = 2 * res + 1;
	}
	return res;
}