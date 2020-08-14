#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	int twoCnt=0;
	int fiveCnt=0;
	for (int i = 2; i <= N; i++) {
		int now = i;
		while (now % 2 == 0) {
			twoCnt++;
			now /= 2;
		}
		while (now % 5 == 0) {
			fiveCnt++;
			now /= 5;
		}
	}
	cout << min(twoCnt, fiveCnt) << '\n';
	return 0;
}