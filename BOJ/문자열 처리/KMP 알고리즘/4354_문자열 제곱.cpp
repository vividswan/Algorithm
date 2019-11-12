#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
char tmp[1000001];
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
int main(void) {
	string p;
	while (1) {
		string p;
		char tmp[1000001];
		scanf("%s", tmp);
		p = tmp;
		if (p.size() == 1 && p[0] == '.') return 0;
		auto pi = getPi(p);
		int len = pi.size() - 1;
		if (pi[len] == 0) printf("%d\n", 1);
		else if (pi.size() % (pi.size() - pi[len]) != 0) printf("%d\n", 1);
		else printf("%d\n", pi.size() / (pi.size() - pi[len]));
	}
	return 0;
}
