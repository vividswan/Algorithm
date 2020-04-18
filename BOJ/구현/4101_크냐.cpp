#include <iostream>
using namespace std;
int main(void) {
	while (1) {
		int a, b;
		cin >> a >> b;
		if (!a && !b) break;
		if (a > b)cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}