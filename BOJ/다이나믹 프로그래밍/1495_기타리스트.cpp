#include <iostream>
using namespace std;
int n, s, m, pos_vol[101], vol[101][1001];
int main(void) {
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) {
		cin >> pos_vol[i];
	}
	vol[0][s] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (vol[i - 1][j] == 1) {
				if (j + pos_vol[i] <= m) vol[i][j + pos_vol[i]] = 1;
				if (j - pos_vol[i] >= 0) vol[i][j - pos_vol[i]] = 1;
			}
		}
	}
	int swc = 0;
	for (int i = m; i >= 0; i--) {
		if (vol[n][i] == 1) {
			cout << i;
			swc++;
			break;
		}
	}
	if (swc == 0) cout << -1;
}