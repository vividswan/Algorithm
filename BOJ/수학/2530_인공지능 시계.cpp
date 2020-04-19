#include <iostream>
using namespace std;
int main(void) {
	int h, m, s;
	cin >> h >> m >> s;
	int val;
	cin >> val;
	s += val;
	m += s / 60;
	s %= 60;
	h += m / 60;
	m %= 60;
	h %= 24;
	cout << h << ' ' << m << ' ' << s << '\n';
	return 0;
}
