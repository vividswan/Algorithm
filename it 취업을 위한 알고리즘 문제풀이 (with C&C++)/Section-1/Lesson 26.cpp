#include <iostream>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int speed[10001];
	for (int i = 1; i <= N; i++) cin >> speed[i];
	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		for (int j = 1; j < i; j++) {
			if (speed[i] > speed[j]) cnt++;
		}
		cout << i - cnt << ' ';
	}
	return 0;
}