#include <iostream>
#include <vector>
using namespace std;
vector<int> adj;
bool dp[4][15001];
int N,result;
int main(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int val;
		cin >> val;
		adj.push_back(val);
	}
	for (int i = 0; i < N; i++) {
		int val = adj[i];
		if (dp[3][val]) result++;
		if (!dp[1][val]) dp[1][val] = true;
		if (!dp[2][val*2]) dp[2][val*2] = true;
		if (!dp[3][val*3]) dp[3][val*3] = true;
	}
}