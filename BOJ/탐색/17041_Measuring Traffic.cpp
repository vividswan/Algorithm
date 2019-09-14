#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<char, pair<int, int>>> v;
int main(void) {
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		char str[10];
		int a, b;
		scanf(" %s", str);
		scanf("%d %d", &a, &b);
		v[i] = { str[1],{a,b} };
	}
	int a = -999999999, b = 999999999;
	for (int i = n; i > 0; i--) {
		if (v[i].first == 'o') {
			a = max(a, v[i].second.first);
			b = min(b, v[i].second.second);
		}
		else if (v[i].first == 'f') {
			a += v[i].second.first;
			b += v[i].second.second;
		}
		else {
			a -= v[i].second.second;
			b -= v[i].second.first;
			a = max(0, a);
		}
	}
	printf("%d %d\n", a, b);
	a = -99999999;
	b = 999999999;
	for (int i = 1; i <= n; i++) {
		if (v[i].first == 'o') {
			a = max(a, v[i].second.first);
			b = min(b, v[i].second.second);
		}
		else if (v[i].first == 'n') {
			a += v[i].second.first;
			b += v[i].second.second;
		}
		else {
			a -= v[i].second.second;
			b -= v[i].second.first;
			a = max(0, a);
		}
	}
	printf("%d %d\n", a, b);
}