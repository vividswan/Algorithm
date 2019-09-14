#include <iostream>
#include <cstring>
#include <deque>
#include <cstdlib>
using namespace std;
int main(void) {
	int roof;
	cin >> roof;
	getchar();
	for (int i = 0; i < roof; i++) {
		deque<int> d;
		int num;
		char command[100010];
		cin.getline(command, 100010);
		cin >> num;
		getchar();
		char str[800020];
		cin.getline(str, 800020);
		int len = strlen(str);
		char go[4];
		int gos = 0;
		for (int i = 1; i < len; i++) {
			if (str[i] == ',' || str[i] == ']') {
				go[gos] = '\0';
				if (go[0] != '\0') d.push_back(atoi(go));
				gos = 0;
				continue;
			}
			else {
				go[gos] = str[i];
				gos++;
			}
		}
		int len2 = strlen(command);
		int swc = 0;
		int ox = 1;
		for (int i = 0; i < len2; i++) {
			if (command[i] == 'D') {
				if (d.empty()) {
					swc++;
					break;
				}
				else {
					if (ox == 1) d.pop_front();
					else if (ox == -1) d.pop_back();
					num--;
				}
			}
			else if (command[i] == 'R') {
				ox = (-1) * ox;
			}
		}
		if (swc) {
			cout << "error" << "\n";
			continue;
		}
		printf("[");
		if (!d.empty()) {
			if (ox == 1) {
				for (int i = 0; i < num - 1; i++) {
					cout << d.front() << ',';
					d.pop_front();
				}
			}
			else if (ox == -1) {
				for (int i = 0; i < num - 1; i++) {
					cout << d.back() << ',';
					d.pop_back();
				}
			}
		}
		if (!d.empty()) cout << d.front() << ']' << "\n";
		else cout << ']' << "\n";
	}
	return 0;
}