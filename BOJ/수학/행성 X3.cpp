#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
long long sum;
long long arr[21];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int val;
		scanf("%d", &val);
		int cnt = 0;
		stack<long long>s;
		while (val) {
			if (val % 2) s.push(1);
			else s.push(0);
			val /= 2;
			cnt++;
		}
		while (!s.empty()) {
			cnt--;
			arr[cnt] += s.top();
			s.pop();
		}
	}
	for (int i = 20; i >= 0; i--) {
		long long minn = arr[i] *(n - arr[i]);
		long long val = pow(2, i);
		sum += minn * val;
	}
	printf("%lld\n", sum);
	return 0;
}