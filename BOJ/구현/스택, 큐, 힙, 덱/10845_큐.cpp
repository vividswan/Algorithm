#include <iostream>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;
int n;
queue<int> q;
int main(void) {
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) {
		char str[30];
		cin.getline(str, 30);
		if (str[0] == 'p' && str[1] == 'u') {
			char str2[30];
			int j = 0;
			for (int i = 5; i <= strlen(str); i++) {
				str2[j] = str[i];
				j++;
			}
			int x = atoi(str2);
			q.push(x);
		}
		else if (str[0] == 'p' && str[1] == 'o') {
			if (q.empty()) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (str[0] == 's') {
			printf("%d\n", q.size());
		}
		else if (str[0] == 'e') {
			printf("%d\n", q.empty());
		}
		else if (str[0] == 'f') {
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else if (str[0] == 'b') {
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}
	}
	return 0;
}