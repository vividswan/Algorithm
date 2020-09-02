#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(void) {
	int N;
	scanf("%d", &N);
	vector<double> adj;
	char str[101];
	scanf("%s", str);
	stack<double> s;
	for (int i = 0; i < N; i++) {
		double num;
		scanf("%lf", &num);
		adj.push_back(num);
	}
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] <= 'Z' && str[i] >= 'A') {
			s.push(adj[str[i] - 'A']);
		}
		else if (str[i] == '+') {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();
			s.push(num1 + num2);
		}
		else if (str[i] == '/') {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();
			s.push(num1 / num2);
		}
		else if (str[i] == '*') {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();
			s.push(num1 * num2);
		}
		else if (str[i] == '-') {
			double num2 = s.top();
			s.pop();
			double num1 = s.top();
			s.pop();
			s.push(num1 - num2);
		}
	}
	printf("%.2lf\n", s.top());
	return 0;
}
