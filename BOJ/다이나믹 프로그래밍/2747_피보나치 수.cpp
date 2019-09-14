#include <iostream>
using namespace std;
int pibo(int);
int memo[46];
int main() {
	int nm;
	cin >> nm;
	pibo(nm);
	cout << memo[nm];
	return 0;
}
int pibo(int nm) {
	if (nm <= 1) {
		memo[nm] = nm;
		return nm;
	}
	if (memo[nm] > 0) return memo[nm];
	else return memo[nm] = pibo(nm - 1) + pibo(nm - 2);
}