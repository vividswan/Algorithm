#include <iostream>
using namespace std;
bool chk[200001];
bool isPrime[200001];
void checkPrime();
int main(void) {
	for (int i = 2; i <= 200001; i++) isPrime[i] = true;
	checkPrime();
	int N;
	cin >> N;
	int result = 0;
	for (int i = 2; i <= N; i++) {
		if (isPrime[i]) result++;
	}
	cout << result << '\n';
	return 0;
}
void checkPrime() {
	for (int i = 2; i < sqrt(200001); i++) {
		if (chk[i]) continue;
		for (int j = i; j < 200001; j += i) {
			chk[j] = true;
			if (i != j) isPrime[j] = false;
		}
	}
}