#include <iostream>
#include <stack>
using namespace std;
int n;
stack<pair<int, int>>s;
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		while (!s.empty()) {
			auto p = s.top();
			if (p.second >= x) {
				printf("%d ", p.first);
				s.push({ i,x });
				break;
			}
			else s.pop();
		}
		if (s.empty()) {
			printf("0 ");
			s.push({ i,x });
			continue;
		}
	}
	return 0;
}