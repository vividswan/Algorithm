#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int n, res;
vector<int> v;
int main(void) {
	scanf("%d", &n);
	v.push_back(-1);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (a > v.back()) {
			v.push_back(a);
			res++;
		}
		else {
			auto go = lower_bound(v.begin(), v.end(), a);
			*go = a;
		}
	}
	printf("%d", res);
}