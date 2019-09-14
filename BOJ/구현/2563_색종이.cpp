#include <iostream>
using namespace std;
int map[102][102], sum;
int main(void) {
	int roof;
	cin >> roof;
	for (int i = 0; i < roof; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 1; j <= 10; j++) {
			for (int l = 1; l <= 10; l++) {
				if (map[a + j][b + l] == 0) {
					sum++;
					map[a + j][b + l] = 1;
				}
			}
		}
	}
	cout << sum;
}