#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
priority_queue<pair<long long, long long>, vector<pair<long long, long long>>> mar;
priority_queue<long long, vector<long long>> sell;
long long tot;
int n, m, r;
long long now_cnt = 0;
long long now_val = 0;
long long arr[100001];
long long cow_val[100001];
vector<long long> cow;
int main(void) {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; i++) {
		long long val;
		scanf("%lld", &val);
		cow.push_back(val);
	}
	sort(cow.begin(), cow.end(), greater<long long>());
	for (int i = 1; i <= m; i++) {
		long long a, b;
		scanf("%lld%lld", &a, &b);
		mar.push({ b,a });
	}
	for (int i = 0; i < n; i++) {
		long long now_cow = cow[i];
		int swc = 0;
		while (swc == 0) {
			if (now_cnt == 0) {
				if (mar.empty()) break;
				now_cnt = mar.top().second;
				now_val = mar.top().first;
				mar.pop();
			}
			if (now_cow <= now_cnt) {
				now_cnt -= now_cow;
				arr[i] += now_cow * now_val;
				tot += now_cow * now_val;
				swc = 1;
				continue;
			}
			else {
				now_cow -= now_cnt;
				arr[i] += now_cnt * now_val;
				tot += now_cnt * now_val;
				now_cnt = 0;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		long long val;
		scanf("%lld", &val);
		sell.push(val);
	}
	for (int i = n - 1; i >= 0; i--) {
		if (sell.empty()) break;
		if (sell.top() > arr[i]) {
			tot -= arr[i];
			tot += sell.top();
			sell.pop();
			continue;
		}
	}
	printf("%lld\n", tot);
}