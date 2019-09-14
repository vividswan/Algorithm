#include <iostream>
#include <stack>
using namespace std;
stack<int>s1;
stack<int>s2;
stack<int>s3;
stack<int>s4;
stack<int>s5;
stack<int>s6;
int main(void) {
	int n, m;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a == 1) {
			if (!s1.empty()) {
				while (!s1.empty() && s1.top() > b) {
					s1.pop();
					cnt++;
				}
				if (!s1.empty()) {
					if (s1.top() == b) continue;
					else {
						s1.push(b);
						cnt++;
						continue;
					}
				}
				else {
					s1.push(b);
					cnt++;
					continue;
				}
			}
			else {
				s1.push(b);
				cnt++;
				continue;
			}
		}
		if (a == 2) {
			if (!s2.empty()) {
				while (!s2.empty() && s2.top() > b) {
					s2.pop();
					cnt++;
				}
				if (!s2.empty()) {
					if (s2.top() == b) continue;
					else {
						s2.push(b);
						cnt++;
						continue;
					}
				}
				else {
					s2.push(b);
					cnt++;
					continue;
				}
			}
			else {
				s2.push(b);
				cnt++;
				continue;
			}
		}
		if (a == 3) {
			if (!s3.empty()) {
				while (!s3.empty() && s3.top() > b) {
					s3.pop();
					cnt++;
				}
				if (!s3.empty()) {
					if (s3.top() == b) continue;
					else {
						s3.push(b);
						cnt++;
						continue;
					}
				}
				else {
					s3.push(b);
					cnt++;
					continue;
				}
			}
			else {
				s3.push(b);
				cnt++;
				continue;
			}
		}
		if (a == 4) {
			if (!s4.empty()) {
				while (!s4.empty() && s4.top() > b) {
					s4.pop();
					cnt++;
				}
				if (!s4.empty()) {
					if (s4.top() == b) continue;
					else {
						s4.push(b);
						cnt++;
						continue;
					}
				}
				else {
					s4.push(b);
					cnt++;
					continue;
				}
			}
			else {
				s4.push(b);
				cnt++;
				continue;
			}
		}
		if (a == 5) {
			if (!s5.empty()) {
				while (!s5.empty() && s5.top() > b) {
					s5.pop();
					cnt++;
				}
				if (!s5.empty()) {
					if (s5.top() == b) continue;
					else {
						s5.push(b);
						cnt++;
						continue;
					}
				}
				else {
					s5.push(b);
					cnt++;
					continue;
				}
			}
			else {
				s5.push(b);
				cnt++;
				continue;
			}
		}
		if (a == 6) {
			if (!s6.empty()) {
				while (!s6.empty() && s6.top() > b) {
					s6.pop();
					cnt++;
				}
				if (!s6.empty()) {
					if (s6.top() == b) continue;
					else {
						s6.push(b);
						cnt++;
						continue;
					}
				}
				else {
					s6.push(b);
					cnt++;
					continue;
				}
			}
			else {
				s6.push(b);
				cnt++;
				continue;
			}
		}
	}
	printf("%d\n", cnt);
}