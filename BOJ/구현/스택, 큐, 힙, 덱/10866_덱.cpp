#include <iostream>
#include <deque>
#include <cstdlib>
#include <cstring>
using namespace std;
int n;
deque<int> d;
int main(void) {
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) {
		char str[30];
		cin.getline(str, 30);
		if (str[0] == 'p' && str[1] == 'u' && str[5] == 'f') {
			char str2[30];
			int j = 0;
			for (int i = 11; i <= strlen(str); i++) {
				str2[j] = str[i];
				j++;
			}
			int x = atoi(str2);
			d.push_front(x);
		}
		else if (str[0] == 'p' && str[1] == 'u' && str[5] == 'b') {
			char str2[30];
			int j = 0;
			for (int i = 10; i <= strlen(str); i++) {
				str2[j] = str[i];
				j++;
			}
			int x = atoi(str2);
			d.push_back(x);
		}
		else if (str[0] == 'p' && str[1] == 'o' && str[4] == 'f') {
			if (d.empty()) printf("-1\n");
			else {
				printf("%d\n", d.front());
				d.pop_front();
			}
		}
		else if (str[0] == 'p' && str[1] == 'o' && str[4] == 'b') {
			if (d.empty()) printf("-1\n");
			else {
				printf("%d\n", d.back());
				d.pop_back();
			}
		}
		else if (str[0] == 's') {
			printf("%d\n", d.size());
		}
		else if (str[0] == 'e') {
			printf("%d\n", d.empty());
		}
		else if (str[0] == 'f') {
			if (d.empty()) printf("-1\n");
			else printf("%d\n", d.front());
		}
		else if (str[0] == 'b') {
			if (d.empty()) printf("-1\n");
			else printf("%d\n", d.back());
		}
	}
	return 0;
}