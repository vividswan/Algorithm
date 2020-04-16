#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void) {
	int n;
	vector<int> adj;
	cin >> n;
	adj.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> adj[i];
	}
	sort(adj.begin(), adj.end());
	for (int i = 0; i < n; i++) cout << adj[i] << '\n';
	return 0;
}