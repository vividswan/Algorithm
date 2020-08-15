#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int N;
	cin >> N;
	vector<int> adj(N);
	for (int i = 0; i < N; i++) {
		cin >> adj[i];
	}
	sort(adj.begin(), adj.end());
	for (int i = 0; i < N; i++) cout << adj[i] << ' ';
	return 0;
}