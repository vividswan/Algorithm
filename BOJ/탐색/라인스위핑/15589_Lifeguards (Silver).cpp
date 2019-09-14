#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<pair<int, int>> v;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		v.push_back({ a,b - 1 });
	}
	v.push_back({ -1,-1 });
	v.push_back({ 1000000001,1000000001 });
	sort(v.begin(), v.end());
	int size = 0;
	int le = v[1].first;
	int ri = v[1].second;
	for (int i = 2; i <= n; i++) {
		if (v[i].first <= ri) {
			ri = max(ri, v[i].second);
		}
		else {
			size += ri - le + 1;
			le = v[i].first;
			ri = v[i].second;
		}
	}
	size += ri - le + 1;
	int bef = -1;
	int res = 1000000001;
	for (int i = 1; i <= n; i++) {
		int l = max(bef + 1, v[i].first);
		int r = min(v[i].second, v[i + 1].first - 1);
		int val = max(0, r - l + 1);
		res = min(res, val);
		bef = max(bef, v[i].second);
	}
	printf("%d\n", size - res);
}