#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool chk[101];
int main(void) {
	int N;
	cin >> N;
	vector<int> adj;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (chk[num]) continue;
		chk[num] = true;
		adj.push_back(num);
	}
	sort(adj.begin(), adj.end(),greater<int>());
	cout << adj[2] << '\n';
	return 0;
}