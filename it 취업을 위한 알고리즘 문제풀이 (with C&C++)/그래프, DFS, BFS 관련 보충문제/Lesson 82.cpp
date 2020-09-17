#include <iostream>
#include <vector>
using namespace std;
bool chk[16];
int arr[16];
int n, r, result;
vector<int> adj;
void recursion(int cnt) {
	if (cnt == r) {
		for (int i = 0; i < adj.size(); i++) {
			cout << adj[i] << ' ';
		}
		cout << '\n';
		result++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = true;
			adj.push_back(arr[i]);
			recursion(cnt + 1);
			chk[i] = false;
			adj.pop_back();		
		}
	}
}
int main(void) {
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	recursion(0);
	cout << result << '\n';
	return 0;
}