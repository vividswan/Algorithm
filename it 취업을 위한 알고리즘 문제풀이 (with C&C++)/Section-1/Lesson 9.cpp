#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<int> adj;
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			adj[j]++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << adj[i] << ' ';
	}
	return 0;
}