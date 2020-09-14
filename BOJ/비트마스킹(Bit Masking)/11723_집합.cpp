#include <iostream>
#include <string>
using namespace std;
int result;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (str == "all") {
			result |= (1 << 21) - 1;
		}
		else if (str == "empty") {
			result = 0;
		}
		else {
			int val;
			cin >> val;
			if (str == "add") {
				result |= (1 << val);
			}
			else if (str == "remove") {
				result &= ~(1 << val);
			}
			else if (str == "check") {
				if (result & (1 << val)) cout << "1\n";
				else cout << "0\n";
			}
			else if (str == "toggle") {
				result ^= (1 << val);
			}
		}
	}
}