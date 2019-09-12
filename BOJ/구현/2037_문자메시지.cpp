#include <iostream>
#include <cstring>
#include <map>
using namespace std;
char str[1001];
int p, w, len, res;
map<char, pair<int, int>> m;
int main(void) {
	m[' '] = { 1,1 };
	m['A'] = { 2,1 };
	m['B'] = { 2,2 };
	m['C'] = { 2,3 };
	m['D'] = { 3,1 };
	m['E'] = { 3,2 };
	m['F'] = { 3,3 };
	m['G'] = { 4,1 };
	m['H'] = { 4,2 };
	m['I'] = { 4,3 };
	m['J'] = { 5,1 };
	m['K'] = { 5,2 };
	m['L'] = { 5,3 };
	m['M'] = { 6,1 };
	m['N'] = { 6,2 };
	m['O'] = { 6,3 };
	m['P'] = { 7,1 };
	m['Q'] = { 7,2 };
	m['R'] = { 7,3 };
	m['S'] = { 7,4 };
	m['T'] = { 8,1 };
	m['U'] = { 8,2 };
	m['V'] = { 8,3 };
	m['W'] = { 9,1 };
	m['X'] = { 9,2 };
	m['Y'] = { 9,3 };
	m['Z'] = { 9,4 };
	cin >> p >> w;
	getchar();
	cin.getline(str, 1001);
	len = strlen(str);
	for (int i = 0; i < len; i++) {
		char a;
		a = str[i];
		if (i == 0) {
			res += m[str[i]].second * p;
			continue;
		}
		else if (m[str[i - 1]].first == m[str[i]].first && str[i] != ' ') {
			res += w;
		}
		res += m[str[i]].second * p;
	}
	cout << res << "\n";
	return 0;
}