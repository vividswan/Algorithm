#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int maxx;
long long res;
vector<int> v;
int arr[200001];
int main(void) {
	scanf("%d", &n);
	res = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		maxx = max(maxx, arr[i]);
	}
	v.resize(maxx + 1);
	for (int i = 1; i <= n; i++) {
		v[arr[i]]++;
	}
	for (int i = 1; i <= maxx; i++) {
		long long cnt = 0;
		for (int j = i; j <= maxx; j += i) {
			cnt += v[j];
		}
		if (cnt > 1) res = max(res, cnt * i);
	}
	printf("%lld\n", res);
	return 0;
}