#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int H, W;
	cin >> H >> W;
	int result = 0;
	vector<vector<int>> map(H + 1, vector<int>(W + 1));
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> map[i][j];
		}
	}
	int requestH, requestW;
	cin >> requestH >> requestW;
	for (int i = 1; i <= H - requestH + 1; i++) {
		for (int j = 1; j <= W - requestW + 1; j++) {
			int nowSum = 0;
			for (int k = i; k <= i + requestH - 1; k++) {
				for (int l = j; l <= j + requestW - 1; l++) {
					nowSum += map[k][l];
				}
			}
			result = max(result, nowSum);
		}
	}
	cout << result << '\n';
	return 0;
}