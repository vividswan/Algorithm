#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<long long> v;
stack<long long> s;
pair<int, long long> p[1000010];
int n, cnt;
int main(void) {
	v.push_back(-9876543210);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long a;
		scanf("%lld,", &a);
		if (v.back() < a) {
			v.push_back(a);
			cnt++;
			p[i] = { cnt,a };
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
			v[idx] = a;
			p[i] = { idx,a };
		}
	}
	int key = cnt;
	for (int i = n - 1; i >= 0; i--) {
		if (key == p[i].first) {
			s.push(p[i].second);
			key--;
			if (key < 1) break;
		}
	}
	printf("%d\n", cnt);
	while (!s.empty()) {
		printf("%lld ", s.top());
		s.pop();
	}
	return 0;
}