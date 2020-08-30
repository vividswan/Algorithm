#include <iostream>
#include <vector>
using namespace std;
vector<int> arr;
int N;
void recursion(int idx,int level) {
	if (level >= N + 1) {
		for (int i = 1; i <= N; i++) {
			if (arr[i]) cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	arr[level] = 1;
	recursion(idx*2,level+1);
	arr[level] = 0;
	recursion(idx * 2 + 1,level+1);
}
int main(void) {
	cin >> N;
	arr.resize(N + 1);
	recursion(1,1);
	return 0;
}