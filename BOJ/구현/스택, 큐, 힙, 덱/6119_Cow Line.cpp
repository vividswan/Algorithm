#include <iostream>
#include <deque>
using namespace std;
int roof;
int st = 1;
deque<int> d;
int main(void) {
	cin >> roof;
	getchar();
	for (int i = 1; i <= roof; i++) {
		char a;
		cin >> a;
		if (a == 'A') {
			char b;
			cin >> b;
			if (b == 'L') {
				d.push_front(st);
				st++;
			}
			else if (b == 'R') {
				d.push_back(st);
				st++;
			}
		}
		if (a == 'D') {
			char b;
			int c;
			cin >> b >> c;
			if (b == 'L') {
				while (c--) {
					d.pop_front();
				}
			}
			if (b == 'R') {
				while (c--) {
					d.pop_back();
				}
			}
		}
	}
	while (!d.empty()) {
		printf("%d\n", d.front());
		d.pop_front();
	}
}