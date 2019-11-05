#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<int> getPi(string p) {
	int m = (int)p.size(), j = 0;
	vector<int> pi(m, 0);
	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
int l;
int main(void) {
	string p;
	scanf("%d ", &l);
	getline(cin, p);
	auto pi = getPi(p);
	int maxx = 0;
	printf("%d\n", l - pi[l - 1]);
}
