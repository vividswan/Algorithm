#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
stack<int>s;
int main() {
	int num;
	scanf("%d ", &num);
	for (int i = 1; i <= num; i++) {
		char str[30];
		cin.getline(str, 30);
		if (str[0] == 'p' && str[1] == 'o') {
			if (s.empty()) printf("-1\n");
			else if (!s.empty()) {
				printf("%d\n", s.top());
				s.pop();
			}
		}
		else if (str[0] == 's') printf("%d\n", s.size());
		else if (str[0] == 'e') printf("%d\n", s.empty());
		else if (str[0] == 't') {
			if (s.empty()) printf("-1\n");
			else if (!s.empty()) {
				printf("%d\n", s.top());
			}
		}
		else {
			char str1[20];
			for (int l = 0; str[l + 4]; l++) {
				str1[l] = str[l + 5];
			}
			s.push(atoi(str1));
		}
	}
}