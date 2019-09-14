#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
vector<pair<int, int>> v;
int n;
int res = 987654321;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int j = a; j < b; j++) arr[j] += 1;
		v.push_back({ a,b - 1 });
	}
	for (int i = 0; i < n; i++) {
		int go = 0;
		for (int j = v[i].first; j <= v[i].second; j++) {
			if (arr[j] == 1) go++;
		}
		res = min(res, go);
	}
	int tot = 0;
	for (int i = 1; i <= 1000; i++) {
		if (arr[i]) tot++;
	}
	printf("%d\n", tot - res);
}