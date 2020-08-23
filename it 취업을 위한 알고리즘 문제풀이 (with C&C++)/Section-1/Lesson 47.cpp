#include <iostream>
using namespace std;
int arr[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int main(void) {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];
				if (x == 0 || x == N + 1 || y == 0 || y == N + 1) {
					cnt++;
					continue;
				}
				if (arr[i][j] > arr[x][y]) cnt++;
			}
			if (cnt == 4) result++;
		}
	}
	cout << result << '\n';
	return 0;
}