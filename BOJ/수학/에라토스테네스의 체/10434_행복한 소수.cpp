#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int era[10010], dis_arr[10010], roof;
int happy(int x);
int main(void) {
	era[0] = 1;
	era[1] = 1;
	for (int i = 2; i < sqrt(10000); i++) {
		if (era[i] == 1) continue;
		int cnt = 2;
		while (cnt * i <= 10000) {
			era[i * cnt] = 1;
			cnt++;
		}
	}
	cin >> roof;
	for (int i = 1; i <= roof; i++) {
		int a, b;
		cin >> a >> b;
		if (happy(b) == 1) {
			if (era[b] == 0) {
				cout << a << ' ' << b << ' ' << "YES" << '\n';
			}
			else cout << a << ' ' << b << ' ' << "NO" << '\n';
		}
		else cout << a << ' ' << b << ' ' << "NO" << '\n';
		memset(dis_arr, 0, sizeof(dis_arr));
	}
	return 0;
}
int happy(int x) {
	while (1) {
		if (x == 1) return 1;
		if (x == 10000) return 1;
		else if (x >= 1000 && x < 10000) {
			x = (x / 1000) * (x / 1000) + ((x / 100) % 10) * ((x / 100) % 10) + ((x / 10) % 10) * ((x / 10) % 10) + (x % 10) * (x % 10);
			if (dis_arr[x] == 1) return 0;
			else dis_arr[x] = 1;
			continue;
		}
		if (x >= 100 && x < 1000) {
			x = (x / 100) * (x / 100) + ((x / 10) % 10) * ((x / 10) % 10) + (x % 10) * (x % 10);
			if (dis_arr[x] == 1) return 0;
			else dis_arr[x] = 1;
			continue;
		}
		else if (x >= 10 && x < 100) {
			x = (x / 10) * (x / 10) + (x % 10) * (x % 10);
			if (dis_arr[x] == 1) return 0;
			else dis_arr[x] = 1;
			continue;
		}
		else if (x > 1 && x < 10) {
			x = x * x;
			if (dis_arr[x] == 1) return 0;
			else dis_arr[x] = 1;
			continue;
		}
	}
}