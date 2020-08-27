#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int S, N;
	cin >> S >> N;
	vector<int> v(S);
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		int pos = -1;
		for (int j = 0; j < S; j++) {
			if (now == v[j]) pos = j;
		}
		if (pos == -1) {
			int j;
			for (j = S-1; j > 0; j--) {
				v[j] = v[j - 1];
			}
			v[j] = now;
;		}
		else {
			int j;
			for (j = pos; j > 0; j--) {
				v[j] = v[j - 1];
			}
			v[j] = now;
		}
	}
	for (int i = 0; i < S; i++) cout << v[i] << ' ';
	cout << '\n';
	return 0;
}