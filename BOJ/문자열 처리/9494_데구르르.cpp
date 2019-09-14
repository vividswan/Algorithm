#include <iostream>
#include <cstring>
using namespace std;
int roof;
int main(void) {
	while (1) {
		int res_max = 0;
		cin >> roof;
		if (roof == 0) break;
		char str[103];
		getchar();
		for (int i = 1; i <= roof; i++) {
			cin.getline(str, 103);
			for (int j = 0; j < strlen(str); j++) {
				if (str[j] == ' ') {
					if (i == 1) {
						res_max = j + 1;
						break;
					}
					if (res_max <= j + 1) {
						res_max = j + 1;
						break;
					}
				}
				if (j == strlen(str) - 1) {
					if (i == 1) {
						res_max = strlen(str) + 1;
						break;
					}
					if (res_max <= strlen(str) + 1) {
						res_max = strlen(str) + 1;
						break;
					}
				}
			}
		}
		cout << res_max << endl;
	}
	return 0;
}