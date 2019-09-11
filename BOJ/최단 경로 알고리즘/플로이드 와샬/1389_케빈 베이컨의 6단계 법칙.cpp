#include <iostream>
#include <algorithm>
#define INF 12345678
using namespace std;
int arr[101][101], n, m;
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > arr[i][k] + arr[k][j]) {
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	int res = INF;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			cnt += arr[i][j];
		}
		res = min(res, cnt);
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			cnt += arr[i][j];
		}
		if (cnt == res) {
			cout << i << '\n';
			return 0;
		}
	}
}