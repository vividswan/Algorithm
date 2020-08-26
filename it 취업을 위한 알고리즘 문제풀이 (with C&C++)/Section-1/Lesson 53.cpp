#include <iostream>
#include <stack>
using namespace std;
int main(void) {
	int N, K;
	scanf("%d%d", &N, &K);
	stack<int> s;
	while (N) {
		s.push(N % K);
		N /= K;
	}
	while (!s.empty()) {
		int now = s.top();
		s.pop();
		if (now >= 10) printf("%c", now - 10 + 'A');
		else printf("%d", now);
	}
	printf("\n");
	return 0;
}