#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, res;
int main(void) {
	v.push_back(-1000000001);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		if (v.back() < a) {
			v.push_back(a);
			res++;
		}
		else {
			auto go = lower_bound(v.begin(), v.end(), a);
			*go = a;
		}
	}
	printf("%d\n", res);
}