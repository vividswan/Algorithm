#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, check[19];
double a, b, rev_a, rev_b, res, a_res, b_res;
void dfs(int idx, int cnt, int ed);
int arr[] = { 0,1,4,6,8,9,10,12,14,15,16,18 };
int main(void) {
	scanf("%d%d", &n, &m);
	a = (double)n / 100.0;
	b = (double)m / 100.0;
	rev_a = 1.0 - a;
	rev_b = 1.0 - b;
	for (int i = 0; i < 12; i++) {
		dfs(0, 0, arr[i]);
		a_res += res * pow(a, arr[i]) * pow(rev_a, 18 - arr[i]);
		b_res += res * pow(b, arr[i]) * pow(rev_b, 18 - arr[i]);
		res = 0;
		memset(check, 0, sizeof(check));
	}
	printf("%.12lf", 1 - a_res * b_res);
}
void dfs(int idx, int cnt, int ed) {
	if (cnt == ed) {
		res++;
		return;
	}
	for (int i = idx; i < 18; i++) {
		if (check[i]) continue;
		check[i]++;
		dfs(i, cnt + 1, ed);
		check[i] = 0;
	}
}