#include <iostream>
#include <map>
using namespace std;
map <string, int> m;
int res;
int main(void) {
	int roof;
	cin >> roof;
	getchar();
	for (int i = 1; i <= roof; i++) {
		char str[20];
		cin.getline(str, 20);
		m[str]++;
	}
	for (int i = 1; i <= roof; i++) {
		char str[20];
		cin.getline(str, 20);
		if (m[str] != 0) {
			res++;
			m[str]--;
		}
	}
	cout << res;
}