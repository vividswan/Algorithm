#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void) {
	int N, M;
	cin >> N >> M;
	vector<int> adj;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		adj.push_back(num);
	}
	sort(adj.begin(), adj.end());
	int le = 0;
	int ri = N - 1;
	int mid;
	while(le <= ri) {
		mid = (le + ri) / 2;
		if (adj[mid] == M) {
			cout << mid + 1 << '\n';
			return 0;
		}
		else if (adj[mid] > M) ri = mid - 1;
		else le = mid + 1;
	}
	return 0;
}