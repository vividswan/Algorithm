#include <iostream>
#include <vector>
using namespace std;
int N, R;
int result;
vector<bool> chk;
void recursion(int idx, int cnt) {
	if (cnt == R) {
		result++;
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!chk[i]) {
			chk[i] = true;
			recursion(i, cnt + 1);
			chk[i] = false;
		}
	}
}
int main(void) {
	cin >> N >> R;
	chk.resize(N);
	recursion(0, 0);
	cout << result << '\n';
	return 0;
}