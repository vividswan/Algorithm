#include <iostream>
using namespace std;
int info[2][101];
int main(void) {
	int N;
	cin >> N;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			cin >> info[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		if (info[0][i] == info[1][i]) cout << 'D' << '\n';
		else if(info[0][i]==info[1][i]+1 || (info[0][i] == 1 && info[1][i]==3)) cout << 'A' << '\n';
		else cout << 'B' << '\n';
	}
	return 0;
}