#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime[1001];
bool chk[1001];
int cnt[1001];
int maxNumbering;
int main(void) {
	for (int i = 2; i < 1001; i++) isPrime[i] = true;
	for (int i = 2; i * i < 1001; i++) {
		if (chk[i]) continue;
		else {
			chk[i] = true;
			for (int j = i+i; j < 1001; j += i) {
				chk[j] = true;
				isPrime[j] = false;
			}
		}
	}
	int N;
	cin >> N;
	cout << N << "! = ";
	for (int now = 2; now <= N; now++) {
		int nowValue = now;
		for (int i = 2; i <= 1000; i++) {
			if (!isPrime[i]) continue;
			if (nowValue == 1) break;
			maxNumbering = max(maxNumbering, i);
			int num = 0;
			while (nowValue % i == 0) {
				num++;
				nowValue /= i;
			}
			cnt[i] += num;
		}
	}
	for (int i = 2; i <= maxNumbering; i++) {
		if (isPrime[i]) cout << cnt[i] << ' ';
	}
	return 0;
}