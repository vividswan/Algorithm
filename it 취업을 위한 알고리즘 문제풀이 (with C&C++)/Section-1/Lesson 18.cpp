#include <iostream>
using namespace std;
int main(void) {
	bool swc = false;
	int result = 0;
	int nowResult = 0;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int noise;
		cin >> noise;
		if (noise <= M) {
			if (nowResult > result) {
				result = nowResult;
			}
			nowResult = 0;
		}
		else {
			swc = true;
			nowResult++;
			if (i == N - 1) {
				if (nowResult > result) {
					result = nowResult;
				}
			}
		}
	}
	if (!swc) cout << -1 << '\n';
	else cout << result << '\n';
	return 0;
}