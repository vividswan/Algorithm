#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int ed = 0;
int res = 0;
int arr[1001];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int s, t, b;
		scanf("%d %d %d", &s, &t, &b);
		ed = max(ed, t);
		for (int i = s; i <= t; i++) arr[i] += b;
	}
	for (int i = 1; i <= ed; i++) {
		res = max(res, arr[i]);
	}
	printf("%d\n", res);
}