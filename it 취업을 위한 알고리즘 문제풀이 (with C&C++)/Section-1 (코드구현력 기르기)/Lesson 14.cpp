#include <iostream>
#include <cmath>
using namespace std;
bool isPrime[100001] = { true };
bool chk[100001];
void checkPrime();
int reverse(int x);
int main(void) {
	for (int i = 2; i < 100001; i++) isPrime[i] = true;
	checkPrime();
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		int reverseNum = reverse(num);
		if (isPrime[reverseNum]) cout << reverseNum << ' ';
	}
	return 0;
}
void checkPrime() {
	for (int i = 2; i < sqrt(100001); i++) {
		if (chk[i]) continue;
		for (int j = i; j < 100001; j += i) {
			chk[j] = true;
			if (i != j) isPrime[j] = false;
		}
	}
}
int reverse(int x) {
	int result = 0;
	while (x) {
		int now = x % 10;
		result *= 10;
		result += now;
		x /= 10;
	}
	return result;
}