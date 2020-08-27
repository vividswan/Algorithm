#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1));
	vector<int> frontView(N + 1);
	vector<int> rightView(N + 1);
	for (int i = 1; i <= N; i++) cin >> frontView[i];
	for (int i = 1; i <= N; i++) cin >> rightView[i];
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			adj[i][j] = min(rightView[i], frontView[j]);
		}
	}
	int result = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			result += adj[i][j];
		}
	}
	cout << result << '\n';
	return 0;
}