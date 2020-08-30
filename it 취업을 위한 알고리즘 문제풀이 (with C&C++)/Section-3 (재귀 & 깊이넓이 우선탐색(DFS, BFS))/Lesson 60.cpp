#include<iostream>
#include<vector>
void recursion(int level, int leftVal, int rightVal);
using namespace std;
int result;
int N;
vector<int> adj;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		adj.push_back(num);
	}
	recursion(1, 0, 0);
	if (result) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
void recursion(int level, int leftVal, int rightVal) {
	if (level == N + 1) {
		if (leftVal == rightVal) result++;
		return;
	}
	recursion(level + 1, leftVal + adj[level - 1], rightVal);
	recursion(level + 1, leftVal, rightVal + adj[level - 1]);
	
}